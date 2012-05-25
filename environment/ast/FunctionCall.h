/**
 * FunctionCall.h
 *
 * @class FunctionCall
 * @author nieznany
 * @date 10-05-2012
 */

#ifndef FUNCTIONCALL_H_
#define FUNCTIONCALL_H_

#include <list>
#include "../Environment.h"
#include "../descriptor/FunctionDescriptor.h"
#include "Expression.h"
#include "../data/Value.h"

namespace matryca
{
class FunctionCall: public Instruction, public Expression
// kolejnosc dziedziczenia ma znaczenie! bo jak najpierw bedzie expression,
// to przy usuwaniu przez shared_ptr !instrukcji! FunctionCall (np. w
// ~FunctionDescriptor) obiekt bedzie usuwany jako instruction
// , czyli usunie obiekt od miejsca gdzie zaczyna sie Instruction
// czyli tak mniej wiecej w srodku obiektu - polowe obiektu usunie
// a polowy nie!
// Dlatego kolejnosc dziedziczenia wielobazowego obiektu, ktory bedzie
// trzymany w shared_ptr powinna odpowiadac kolejnosci dealokacji
// (mozliwe ze jest to po prostu jakis bug w booscie)
{
public:
    // TODO zmienic na ogolne value
    typedef Environment::SymbolID SymbolID;
    typedef Expression::ExpressionPtr ExpressionPtr;
    typedef Expression::ExpressionPtrList ExpressionPtrList;
    typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;
    typedef FunctionDescriptor::FuncDescPtr FuncDescPtr;
    typedef FunctionDescriptor::ValueList ValueList;

    FunctionCall(const SymbolID &id, const ExpressionPtrList &args);
    virtual ~FunctionCall();
private:
    // TODO zmienic na Value
    // zapisuje wartosc wyrazenia na koniec podanej listy
    void calcArg(Environment &env, ExpressionPtr e_ptr, ValueList &list);
    Value doExecute(Environment &env);

    SymbolID id_;
    // lista wyrazen jako argumenty aktualne funkcji
    ExpressionPtrList expressions_;
};

} /* namespace matryca */
#endif /* FUNCTIONCALL_H_ */
