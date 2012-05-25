/**
 * MatrycaDriver.h
 *
 * @class MatrycaDriver
 * @brief Brief description.
 * @date 04-05-2012
 */

#ifndef DRIVER_H_
#define DRIVER_H_
#include "scanner/Scanner.h"
#include "environment/Environment.h"
#include "environment/descriptor/FunctionDescriptor.h"
#include "environment/ast/Expression.h"

#include <boost/shared_ptr.hpp>

namespace matryca
{
class Driver
{
public:
    typedef boost::shared_ptr<Scanner> ScannerPtr;
    typedef boost::shared_ptr<Environment> EnvironmentPtr;
    typedef FunctionDescriptor::InstructionPtr InstructionPtr;
    typedef FunctionDescriptor::InstructionPtrList InstructionPtrList;
    typedef FunctionDescriptor::IDList IDList;
    typedef FunctionDescriptor::SymbolID SymbolID;
    typedef Expression::ExpressionPtr ExpressionPtr;
    typedef Expression::ExpressionPtrList ExpressionPtrList;
    typedef Expression::ExpressionPtrMatrix ExpressionPtrMatrix;

    Driver();

    ScannerPtr getScanner();
    EnvironmentPtr parseStream(std::istream &in, std::ostream &out, std::ostream &err);

    void addFunction(const Environment::SymbolID &id, const IDList &params, const InstructionPtrList &list);
    /**
     * Powoduje utworzenie nowej, pustej lokalnej listy instrukcji
     *
     * @return zwraca stara lokalna liste instrukcji (ktore zostaly dodane do listy local_
     *         do momentu wywolania tej funkcji). Zwraca wskaznik! bo bison
     *         uzywa unii do trzymania wartosci poszczegolnych, wiec moze
     *         trzymac co najwyzej wskaznik do obiektu
     *
     */
    InstructionPtrList* getLocalInstructionPtrList();

    /**
     * Dodaje na szczyt stosu pusta liste instrukcji
     */
    void pushLocalInstructionPtrList();
    /**
     * Dodaje instrukcje do lokalnej listy instrukcji (local_)
     * przydatne dla wywolan bisona
     *
     * @param instruction - dodawania instrukcja
     */
    void addLocalInstruction(InstructionPtr instruction);

    /**
     * dodaje nowa instrukcje do listy instrukcji glownej procedury
     * programu (global_).
     *
     * @param instruction - dodawana instrukcja
     */
    void addGlobalInstruction(InstructionPtr instruction);

    // analogiczne dzialanie jak dla "instrukcji" powyzej
    void addExpression(ExpressionPtr);
    void pushExpressionPtrList();
    ExpressionPtrList* getExpressionPtrList();

    // analogiczne dzialanie jak dla "instrukcji" powyzej
    void addExpressionList(const ExpressionPtrList&);
    void pushExpressionPtrMatrix();
    ExpressionPtrMatrix* getExpressionPtrMatrix();

    // analogicznie do powyzszych dla listy parametrow
    void addID(const SymbolID &);
    IDList* getIDList();

    virtual ~Driver();
private:
    /** aktualnie uzywany skaner */
    ScannerPtr scanner_;
    /** aktualnie tworzone srodowisko uruchomieniowe */
    EnvironmentPtr environment_;

    //TODO sprobowac zrobic to jakos inaczej, moze bison jakos pozwala na wywolanie funkcji
    // przed zaglebieniem sie w poddrzewo o danym wezle - korzeniu, oraz po
    // przetworzeniu wszystkich instrukcji?
    /** local_ - lista instrukcji dla obecnego kontekstu (funkcja, blok instrukcji),
     *  jest przypisywana np. instrukcji warunkowej w momencie zakonczenia bloku
     *  instrukcji, local_ zostaje nastepnie ustawiona jako nowa pusta lista. */
    InstructionPtrList global_;
    /**
     * stos z aktualnie przegladana lista instrukcji (na szczycie stosu najglebszy zakres)
     * Kazdy element stosu posiada instrukcji dla poszczegolnych
     * zakresow
     */
    std::vector<InstructionPtrList> local_;
    // ta sama sytuacja, tylko dla listy wyrazen, np. dla wywolania funkcji

    std::vector<ExpressionPtrList> expressions_;
    // tak samo dla macierzy wyrazen
    std::vector<ExpressionPtrMatrix> matrix_;
    // tak samo dla listy parametrow, tylko STOS nie jest potrzebny, bo lista parametrow nie jest zagniezdzana
    IDList currentIDs_;
};

} /* namespace matryca */
#endif /* MATRYCADRIVER_H_ */
