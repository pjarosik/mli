/**
 * LoopInstruction.cc
 *
 * @class LoopInstruction
 * @brief Brief description.
 * @author nieznany
 * @date 11-05-2012
 */

#include "LoopInstruction.h"
#include <stdexcept>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

namespace matryca
{

LoopInstruction::LoopInstruction(ExpressionPtr cond_expr, InstructionPtrList instructions) :
        condition_(cond_expr), instructions_(instructions)
{
}

LoopInstruction::~LoopInstruction()
{
}

Value LoopInstruction::doExecute(Environment & e)
{
    if(!condition_)
        throw new runtime_error("LoopInstruciton::doExecute: condition_ jest pusty (NULL)");
    while(condition_->execute(e) != Value(0)) // 0 to warunek koncowy petli
    { // wykonanie kolejnych iteracji petli
        for_each(instructions_.begin(), instructions_.end(), bind(&Instruction::execute, _1, ref(e)));
    }
}

} /* namespace matryca */
