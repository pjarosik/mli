%{
#include <boost/lexical_cast.hpp>
#include <string>
#include "Scanner.h"
#include <iostream>

%}

/* OPCJE FLEX */

 /* zeby nie bylo wykonywane domyslne kopiowanie na yyout niedopasowanych znakow */
%option nodefault
%option noyywrap
%option c++
/* zeby mozna bylo wyswietlac nr linii */
%option yylineno

/* wyjsciowa klasa flexa bedzie Scanner */
%option yyclass="Scanner"

/* do dokladnego sledzenia polozenia pozycji */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

/* DEFINICJE POMOCNICZE */
 
litera [A-Za-z]
cyfra [0-9]
cyfra_niezerowa [1-9]
id {litera}({litera}|{cyfra}|_)*
liczba ({cyfra_niezerowa}{cyfra}*|0)
liczba_ulamkowa {liczba}"."[0-9]+
biale_znaki [ \t\n]+
znak "+"|"-"
op_przypisania "="
op_multiplikatywny "*"|"/"|and

%x KOMENTARZE
%%

%{
    /* kazdy kolejny krok ustawia pozycje */
    yylloc->step();
%}

{liczba_ulamkowa} {
    yylval->double_val = boost::lexical_cast<double>(yytext);
    return matryca::Parser::token::LICZBA_ULAMKOWA;
}

{liczba} {
    yylval->int_val = boost::lexical_cast<int>(yytext);
    return matryca::Parser::token::LICZBA;
}

{znak} {
    yylval->char_val = *yytext;
    return matryca::Parser::token::ZNAK;
}

or {
    yylval->char_val = *yytext;
    return matryca::Parser::token::OP_OR;
}

{op_multiplikatywny} {
    yylval->char_val = *yytext;
    return matryca::Parser::token::OP_MULTIPLIKATYWNY; // dla "and" zwracane jest 'a'
}

">" {
    yylval->char_val = '>';
    return matryca::Parser::token::OP_RELACJI;
}

">=" {
    yylval->char_val = 'g';
    return matryca::Parser::token::OP_RELACJI;
}

"<" {
    yylval->char_val = '<';
    return matryca::Parser::token::OP_RELACJI;
}

"<=" {
    yylval->char_val = 'l';
    return matryca::Parser::token::OP_RELACJI;
}

"==" {
    yylval->char_val = '=';
    return matryca::Parser::token::OP_RELACJI;
}

"!=" {
    yylval->char_val = '!';
    return matryca::Parser::token::OP_RELACJI;
}

{op_przypisania} {
    return matryca::Parser::token::OP_PRZYPISANIA;
}

if {
    return matryca::Parser::token::IF;
}

else {
    return matryca::Parser::token::ELSE;
}

while {
    return matryca::Parser::token::WHILE;
}

not {
    yylval->char_val = 'n';
    return matryca::Parser::token::NOT;
}

val {
    return matryca::Parser::token::VAL;
}

defn {
    return matryca::Parser::token::DEFN;
}

{id} {
    yylval->string_val = new std::string(yytext, yyleng);
    return matryca::Parser::token::ID;
}

[ \t\r]+ {
    yylloc->step();
}
<INITIAL,KOMENTARZE>\n {
    yylloc->lines(yyleng); yylloc->step();
}

"/*" {
    BEGIN(KOMENTARZE); // tryb komentarzy
}

<KOMENTARZE>"*/" {
    yylloc->step();
    BEGIN(INITIAL); // powrot do ogolnego trybu
}

<KOMENTARZE>. { /* wszystko co nie jest \n */
    yylloc->step();
}

. { // pozostale znaki do bisona (w tym '(' ')' itd.)
    return static_cast<matryca::Parser::token_type>(*yytext);
}
