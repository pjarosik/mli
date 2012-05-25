/**
 * ConditionalInstruction.h
 *
 * @class ConditionalInstruction
 * @brief Brief description.
 * @author nieznany
 * @date 10-05-2012
 */

#ifndef CONDITIONALINSTRUCTION_H_
#define CONDITIONALINSTRUCTION_H_

#include "Instruction.h"
#include "Expression.h"
#include "../Environment.h"
#include "../data/Value.h"

#include <list>

namespace matryca
{

class ConditionalInstruction : public Instruction
{
public:
    typedef Expression::ExpressionPtr ExpressionPtr;
    typedef Instruction::InstructionPtrList InstructionPtrList;
    typedef Instruction::InstructionPtr InstructionPtr;

    // jak nie poda sie else_istr to wersja if bez else (elseInstructions_ pusta).
    ConditionalInstruction(ExpressionPtr cond_expr, const InstructionPtrList &then_instrs, const InstructionPtrList &else_instr = InstructionPtrList());
    virtual ~ConditionalInstruction();
private:
    // zwraca wartosc warunku
    Value doExecute(Environment& e);

    ExpressionPtr condition_;
    InstructionPtrList thenInstructions_;
    InstructionPtrList elseInstructions_;
};

} /* namespace matryca */
#endif /* CONDITIONALINSTRUCTION_H_ */
