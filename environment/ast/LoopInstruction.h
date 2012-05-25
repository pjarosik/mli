/**
 * LoopInstruction.h
 *
 * @class LoopInstruction
 * @brief Brief description.
 * @author nieznany
 * @date 11-05-2012
 */

#ifndef LOOPINSTRUCTION_H_
#define LOOPINSTRUCTION_H_
#include "Instruction.h"
#include "Expression.h"

namespace matryca
{

class LoopInstruction : public Instruction
{
public:
    typedef Expression::ExpressionPtr ExpressionPtr;
    typedef Instruction::InstructionPtrList InstructionPtrList;
    typedef Instruction::InstructionPtr InstructionPtr;

    LoopInstruction(ExpressionPtr cond_expr, InstructionPtrList instructions);
    virtual ~LoopInstruction();
private:
    Value doExecute(Environment& e);

    ExpressionPtr condition_;
    InstructionPtrList instructions_;
};

} /* namespace matryca */
#endif /* LOOPINSTRUCTION_H_ */
