/**
 * AssigmentInstruction.cc
 *
 * @class AssigmentInstruction
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#include "AssignmentInstruction.h"
#include "VariableExpression.h"
#include "../exceptions/NotVariableException.h"
#include "../exceptions/SymbolNotFoundException.h"
#include <stdexcept>
#include <iostream>

using namespace boost;

namespace matryca
{
// TODO niebezpieczne uznanie id za wyrazenie, moze byc nim nawet wynik OperatorExpression
AssignmentInstruction::AssignmentInstruction(ExpressionPtr id, ExpressionPtr expr, bool local) :
        id_(id), expression_(expr), local_(local)
{
}

AssignmentInstruction::~AssignmentInstruction()
{
}

Value AssignmentInstruction::doExecute(Environment &env)
{
    SymbolID id;
    SymbolDescPtr desc;

    try
    {
        VariableExpression& var_exp = dynamic_cast<VariableExpression&>(*id_);
        id = var_exp.getID();
    }
    catch (const std::bad_cast& e)
    {
        throw std::runtime_error("AssigmentInstruction::doExecute: podane id nie jest VariableExpression");
    }
    try
    {
        if(local_)
            desc = env.findLocal(id);
        else
            desc = env.find(id);
    }
    catch (const SymbolNotFoundException &e)
    { // przypisanie jest rownoznaczne z dodaniem symbolu do zakresu globalnego
        desc = SymbolDescPtr(new VariableDescriptor(id, 0));
        if(local_)
            env.add(desc); // TODO moze dodac globalnie! (udokumentowac to, ze val mozna uzyc tez w zakresie globalnym)
        else
            env.addGlobal(desc); // globalne! do zakresu lokalnego dodawane jest przy uzyciu "val"
    }
    if (desc->getType() != SymbolDescriptor::VARIABLE)
    {
        throw NotVariableException(id);
    }
    VarDescPtr var = static_pointer_cast<VariableDescriptor>(desc);
    var->setValue(expression_->execute(env));
    return var->getValue(); // zwraca przypisany wynik
}

} /* namespace matryca */
