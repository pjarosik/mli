/**
 * AssigmentInstruction.h
 *
 * @class AssigmentInstruction
 * @brief Brief description.
 * @author nieznany
 * @version APP_V.MODULE_V.CLASS_V
 * @date 06-05-2012
 */

#ifndef ASSIGMENTINSTRUCTION_H_
#define ASSIGMENTINSTRUCTION_H_

#include <boost/shared_ptr.hpp>

#include "Instruction.h"
#include "OperatorExpression.h"
#include "../data/Value.h"

#include "../descriptor/VariableDescriptor.h"

namespace matryca
{

class AssignmentInstruction : public Instruction
{
public:
    typedef SymbolDescriptor::SymbolID SymbolID;
    typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;
    typedef VariableDescriptor::VarDescPtr VarDescPtr;

    typedef OperatorExpression::ExpressionPtr ExpressionPtr;

    AssignmentInstruction(ExpressionPtr id, ExpressionPtr expr, bool local = false);
    virtual ~AssignmentInstruction();
private:
    // zwraca przypisany wynik
    Value doExecute(Environment &);
    ExpressionPtr id_;
    ExpressionPtr expression_;
    /**
     * czy - w przypadku koniecznosci utworzenia symbolu - PROBOWAC dodac
       symbol do tablicy lokalnej (jezeli zakres globalny to i tak doda globalnie)-
       -  domyslnie ustawione, ze nie
     */
    bool local_;

};

} /* namespace matryca */
#endif /* ASSIGMENTINSTRUCTION_H_ */
