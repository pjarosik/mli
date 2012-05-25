/**
 * ConditionalInstruction.cc
 *
 * @class ConditionalInstruction
 * @brief Brief description.
 * @author nieznany
 * @date 10-05-2012
 */

#include "ConditionalInstruction.h"
#include <boost/bind.hpp>
#include <stdexcept>

using namespace boost;
namespace matryca
{

ConditionalInstruction::ConditionalInstruction(ExpressionPtr cond_expr, const InstructionPtrList &then_instrs,const InstructionPtrList &else_instr) :
        condition_(cond_expr), thenInstructions_(then_instrs), elseInstructions_(else_instr)
{
}

ConditionalInstruction::~ConditionalInstruction()
{
}

Value ConditionalInstruction::doExecute(Environment & env)
{
    // male sprawdzenia poprawnosci danych
    if (!condition_)
        throw new std::runtime_error("ConditionInstruction:doExecute: ExpressionPtr condition_ jest pusty (NULL)");
    Value cond_result = condition_->execute(env);
    if (cond_result != Value(0))
    { // warunek prawdziwy
        std::for_each(thenInstructions_.begin(), thenInstructions_.end(), bind(&Instruction::execute, _1, ref(env)));
    }
    else
    {
        std::for_each(elseInstructions_.begin(), elseInstructions_.end(), bind(&Instruction::execute, _1, ref(env)));
    }
    return cond_result; // zwraca wartosc warunku
}

} /* namespace matryca */
