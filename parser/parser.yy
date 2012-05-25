%{
#include <string>
#include "../Driver.h"
#include "../scanner/Scanner.h"
#include "../environment/ast/ValueExpression.h"
#include "../environment/ast/VariableExpression.h"
#include "../environment/ast/OperatorExpression.h"
#include "../environment/ast/AssignmentInstruction.h"
#include "../environment/ast/ConditionalInstruction.h"
#include "../environment/ast/Instruction.h"
#include "../environment/ast/Expression.h"
#include "../environment/ast/FunctionCall.h"
#include "../environment/descriptor/FunctionDescriptor.h"
#include "../environment/ast/LoopInstruction.h"
#include "../environment/data/Value.h"
#include "../environment/ast/MatrixExpression.h"
#include "../environment/ast/MatrixElementExpression.h"
using namespace matryca;

// typedefy dla elementow ast

typedef Instruction::InstructionPtr InstructionPtr;
typedef Instruction::InstructionPtrList InstructionPtrList;
typedef Expression::ExpressionPtr ExpressionPtr;
typedef Expression::ExpressionPtrList ExpressionPtrList;
typedef Expression::ExpressionPtrMatrix ExpressionPtrMatrix;
typedef FunctionDescriptor::IDList IDList;
typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;

#undef yylex
#define yylex driver.getScanner()->yylex
// parser bedzie pobieral tokeny posrednio przez driver
%}

%require "2.4.1" // wersja uzytego generatora
%skeleton "lalr1.cc"// wersja c++ szablonu
%defines// wypisanie do oddzielnego pliku .h definicji tokenow
%define parser_class_name "Parser"// nazwa tworzonej klasy
%define namespace "matryca"

%parse-param
{   matryca::Driver &driver} // parametr wywolania yyparse
// TODO dodatkowo trzeba bedzie przekazac analizatorowi leksykalnemu: jakas tablice funkcji
// (zeby mozna bylo dodawac instrukcje dla funkcji), no i dostep do drzewa instrukcji
%code requires
{ // forward declaration zeby miec dostep do obiektu klasy Driver
    namespace matryca
    {
        class Driver;
    }
}

%debug
%error-verbose

%locations


// gramatyka

%union
{ // ustawia nowy typ dla yylval (czyli jakie wartosci moze przyjac yylval
    // dla terminali
    char char_val;
    int int_val;
    double double_val;
    std::string *string_val;
    // typy dla nieterminali
    matryca::Instruction* instruction_ptr;
    // musi byc wskaznik na liste wskaznikow, bo bison trzyma wyniki
    // w unii, a unia nie pozwala trzymac obiektow, musza byc wiec
    // wskazniki na nie
    matryca::Instruction::InstructionPtrList* instruction_ptr_list_ptr;
    matryca::Expression* expression_ptr;
    matryca::Expression::ExpressionPtrList* expression_ptr_list_ptr;
    matryca::FunctionCall* function_call_ptr;
    matryca::FunctionDescriptor::IDList* id_list_ptr;
    matryca::Expression::ExpressionPtrMatrix* expression_ptr_matrix_ptr;
}

%token <string_val> ID "identyfikator"
%token <int_val> LICZBA "liczba"
%token <double_val> LICZBA_ULAMKOWA "liczba ulamkowa"
%token <char_val> ZNAK "znak"
%token <char_val> OP_MULTIPLIKATYWNY "operator multiplikatywny" // char_val - dla "and" zwracana jest litera 'a'
%token <char_val> OP_RELACJI "operator relacji"
%token OP_PRZYPISANIA "operator przypisania"
%token IF "if"
%token <char_val> OP_OR "operator or"
%token ELSE "else"
%token WHILE "while"
%token <char_val> NOT "not"
%token VAL "val"
%token DEFN "defn"

%type <id_list_ptr> lista_parametrow_formalnych
%type <char_val> op_addytywny
%type <function_call_ptr> wywolanie_funkcji
%type <instruction_ptr_list_ptr> blok_instrukcji wynik_warunku
%type <instruction_ptr> instrukcja instrukcja_warunkowa instrukcja_petli utworzenie_zmiennej
%type <expression_ptr> czynnik skladnik wyrazenie_arytmetyczne wyrazenie zmienna macierz
%type <expression_ptr_list_ptr> argumenty


%start lista_operacji
%%

lista_operacji:
    lista_operacji operacja
    {
        // nic
    }
    | operacja
    {
        // nic
    }

operacja:
    definicja_funkcji
    {
        // nic
    }
    | instrukcja
    {
        driver.addGlobalInstruction(InstructionPtr($1));
    }

definicja_funkcji:
    DEFN ID '(' lista_parametrow_formalnych ')' blok_instrukcji
    {
        driver.addFunction(*$2, *$4, *$6);
        delete $2; delete $4; delete $6; // juz nie potrzebne
    }

lista_parametrow_formalnych:
    lista_identyfikatorow
    {
        $$ = driver.getIDList();
    }
    | /* epsilon */
    {
        $$ = new IDList;
    }

lista_identyfikatorow:
    lista_identyfikatorow ',' ID
    {
        driver.addID(*$3);
        delete $3;
    }
    | ID
    {
        driver.addID(*$1);
        delete $1;
    }

blok_instrukcji:
    {   // akcja przed wejsciem do bloku instrukcji
        driver.pushLocalInstructionPtrList();
    }
    '{' lista_instrukcji '}'
    {
        $$ = driver.getLocalInstructionPtrList();
    }

lista_instrukcji:
    lista_instrukcji instrukcja
    {
        driver.addLocalInstruction(InstructionPtr($2));
    }
    | instrukcja
    {
        driver.addLocalInstruction(InstructionPtr($1));
    }

instrukcja:
    ID OP_PRZYPISANIA wyrazenie ';'
    {
        $$ = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*$1)), ExpressionPtr($3));
        delete $1;
        $$->setLocation(yylloc);
    }
    | utworzenie_zmiennej
    {
        $$ = $1;
        $$->setLocation(yylloc);
    }
    | instrukcja_warunkowa
    {
        $$ = $1;
    }
    | wywolanie_funkcji ';'
    {
        $$ = $1; // wywolanie funkcji to instrukcja i wyrazenie jednoczesnie
        $$->setLocation(yylloc);
    }
    | instrukcja_petli
    {
        $$ = $1;
    }

utworzenie_zmiennej:
    VAL ID ';'// musi byc ID, bo nie ma sensu tworzenie zmiennej lokalnej elementu macierzy
    { // przypisuje 0 do tworzonej na stosie wartosci lub wartosci globalnej
        $$ = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*$2)), ExpressionPtr(new ValueExpression(0)), true);
        delete $2;
    }
    | VAL ID OP_PRZYPISANIA wyrazenie ';'
    {
        $$ = new AssignmentInstruction(ExpressionPtr(new VariableExpression(*$2)), ExpressionPtr($4), true);
        delete $2;
    }

zmienna:
    ID
    {
        $$ = new VariableExpression(*$1);
        delete $1;
    }
    | ID '|' wyrazenie ',' wyrazenie '\\'
    {
        $$ = new MatrixElementExpression(*$1, ExpressionPtr($3), ExpressionPtr($5));
        delete $1;
    }

macierz:
    '['
    {driver.pushExpressionPtrMatrix();}
        macierz_wyrazen ']'
    {
        $$ = new MatrixExpression(*(driver.getExpressionPtrMatrix()));
    }

macierz_wyrazen:
    macierz_wyrazen ';' argumenty
    {
        driver.addExpressionList(*$3);
        delete $3;
    }
    | argumenty
    {
        driver.addExpressionList(*$1);
        delete $1;
    }

op_addytywny:
    ZNAK
    {
        $$ = $1;
    }
    | OP_OR
    {
        $$ = $1;
    }

wyrazenie:
    wyrazenie_arytmetyczne
    {
        $$ = $1;
    }
    | wyrazenie OP_RELACJI wyrazenie_arytmetyczne // OP_RELACJI ma najnizszy priorytet - ma to sens np. dla 3+3*3 ==12
    {
        $$ = new OperatorExpression($2, ExpressionPtr($1), ExpressionPtr($3));
        $$->setLoc(yylloc);
    }

wyrazenie_arytmetyczne:
    skladnik
    {
        $$ = $1;
    }
    | wyrazenie_arytmetyczne op_addytywny skladnik
    {
        $$ = new OperatorExpression($2, ExpressionPtr($1), ExpressionPtr($3));
        $$->setLoc(yylloc);
    }

skladnik:
    czynnik
    {
        $$ = $1;
    }
    | ZNAK czynnik
    { // to jest mnozenie odpowiednio +/- 1 * czynnik
        $$ = new OperatorExpression('*',
                                    ExpressionPtr(new OperatorExpression(
                                            $1,
                                            ExpressionPtr(new ValueExpression(0)),
                                            ExpressionPtr(new ValueExpression(1)))), // 0 +/- 1
                                    ExpressionPtr($2));
        $$->setLoc(yylloc);
    }
    | skladnik OP_MULTIPLIKATYWNY czynnik
    {
        $$->setLoc(yylloc);
        $$ = new OperatorExpression($2, ExpressionPtr($1), ExpressionPtr($3));
    }

czynnik:
    LICZBA
    {
        $$ = new ValueExpression($1);
        $$->setLoc(yylloc); // zapamietanie pozycji wyrazenia - strategia - jak najglebiej
    }
    | LICZBA_ULAMKOWA
    {
        $$ = new ValueExpression($1);
        $$->setLoc(yylloc);
    }
    | macierz
    {
        $$ = $1;
        $$->setLoc(yylloc);
    }
    | zmienna
    {
        $$ = $1;
        $$->setLoc(yylloc);
    }
    | wywolanie_funkcji
    {
        $$ = $1; // wywolanie funkcji to wyrazenie i instrukcja
        $$->setLoc(yylloc);
    }
    | '(' wyrazenie ')'
    {
        $$ = $2;
    }
    | NOT czynnik
    { // NOT jest operatorem oznaczanym 'n'
        $$ = new OperatorExpression($1, ExpressionPtr(), ExpressionPtr($2));
    }

wywolanie_funkcji:
    ID '(' argumenty ')'
    {
        $$ = new FunctionCall(*$1, *$3);
        // argumenty skopiowane, mozna usunac
        delete $1;
        delete $3;
    }

// argumenty to po prostu lista wyrazen lub pusta lista wyrazen
argumenty:
    {driver.pushExpressionPtrList();}
    lista_wyrazen
    {
        $$ = driver.getExpressionPtrList();
    }
    | /* epsilon */ // pusta lista wyrazen - brak argumentow
    {
        $$ = new ExpressionPtrList; // pusta lista wyrazen
    }

lista_wyrazen:
    lista_wyrazen ',' wyrazenie
    {
        driver.addExpression(ExpressionPtr($3));
    }
    | wyrazenie
    {
        driver.addExpression(ExpressionPtr($1));
    }

instrukcja_warunkowa:
    IF '(' wyrazenie ')' wynik_warunku
    {
        // koniec ze wskaznikami na liste instrukcji - wyluskuje...
        $$ = new ConditionalInstruction(ExpressionPtr($3), *$5);
        //... $5 skopiowane w poprzedniej instrukcji wiec stara liste usuwam
        // malo efektywne ale inaczej sie nie da
        delete $5;
    }
    | IF '(' wyrazenie ')' wynik_warunku ELSE wynik_warunku
    {
        $$ = new ConditionalInstruction(ExpressionPtr($3), *$5, *$7);
        // $5, $7 skopiowane w poprzedniej instrukcji
        delete $5;
        delete $7;
    }

instrukcja_petli:
    WHILE '(' wyrazenie ')' wynik_warunku
    {
        $$ = new LoopInstruction(ExpressionPtr($3), *$5);
        delete $5;
    }

wynik_warunku:
    blok_instrukcji
    {
        $$ = $1;
    }
    | instrukcja
    {
        // wynikiem jest pojedyncza instrukcja
        // tu nie trzeba umieszczac nic na poczatku stosu ani z niego zdejmowac - to tylko jedna
        // instrukcja
        InstructionPtrList *instruction = new InstructionPtrList;
        instruction->push_back(InstructionPtr($1));
        $$ = instruction;
    }
%%

void matryca::Parser::error(const matryca::Parser::location_type &loc, const std::string &msg)
{
    // TODO przerucic obsluge bledow do driver
    std::cerr << loc << " : " << msg << std::endl;
    exit(-1);
}

