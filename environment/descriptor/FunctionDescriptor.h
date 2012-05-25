/**
 * FunctionDescriptor.h
 *
 * @class FunctionDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef FUNCTIONDESCRIPTOR_H_
#define FUNCTIONDESCRIPTOR_H_

#include <boost/shared_ptr.hpp>
#include <list>

#include "SymbolDescriptor.h"
#include "VariableDescriptor.h"
#include "../ast/Instruction.h"
#include "../data/Value.h"

namespace matryca
{

class FunctionDescriptor : public SymbolDescriptor
{
public:
    const static int RET_VALUE = 0;
    typedef boost::shared_ptr<FunctionDescriptor> FuncDescPtr;
    typedef VariableDescriptor::VarDescPtr VarDescPtr;
    // lista symboli jako paramtetrow formalnych funkcji
    typedef std::list<SymbolID> IDList;

    /** lista parametrow aktualnych */
    typedef std::list<Value> ValueList;
    typedef Instruction::InstructionPtr InstructionPtr;
    typedef Instruction::InstructionPtrList InstructionPtrList;

    FunctionDescriptor();
    FunctionDescriptor(const SymbolID &id,const IDList &params, const InstructionPtrList &list);
    virtual ~FunctionDescriptor();
    /**
     * Wykonuje funkcje w kontekscie danego interpretera dla danej listy wartosci.
     *
     * @param interpreter
     * @param no_stack - zeby nie tworzyc stosu w srodowisku dla tej funkcji
     */
    // TODO zmienic na Value
    virtual Value execute(Environment &env, const ValueList &list, bool no_stack = false);



    Type getType() const;
    virtual SymbolID getSymbol() const;
private:
    /** tworzy w srodowisku nowy zakres dla danej funkcji
     *  i tworzy odpowiednie wpisy dla poszczegolnych parametrow
     *  (w tym takze parametr o nazwie funkcji - przez ktory
     *  bedzie zwracany wynik wywolania, poczatkowo ma ustawiona
     *  wartosc = 0; nie powoduje to konfliktu z wywolaniem funkcji
     *  o tej samej nazwie, gdyz funkcje sa tylko w zakresie globalnym)  */
    void createLocalVariables(Environment &env, const ValueList &init_val);

    /** sprzata po wywolanej funkcji (usuwa m.in. tablice symboli
     *  ze stosu srodowiska uruchomieniowego).
     */
    void cleanUp(Environment &env);

    /** id symbolu */
    SymbolID id_;
    /** lista symboli parametrow formalnych **/
    IDList params_;
    /** lista instrukcji funkcji */
    InstructionPtrList instructions_;
};

} /* namespace matryca */
#endif /* FUNCTIONDESCRIPTOR_H_ */
