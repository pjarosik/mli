/**
 * FunctionCall.cc
 *
 * @class FunctionCall
 * @author nieznany
 * @date 10-05-2012
 */

#include <boost/bind.hpp>
#include "FunctionCall.h"
#include "../exceptions/NotFunctionException.h"

using namespace std;
using namespace boost;
namespace matryca
{

FunctionCall::FunctionCall(const SymbolID & id, const ExpressionPtrList & args) :
        id_(id), expressions_(args)
{
}

void FunctionCall::calcArg(Environment &env, ExpressionPtr e_ptr, ValueList &list)
{
    list.push_back(e_ptr->execute(env));
}

FunctionCall::~FunctionCall()
{
}

Value FunctionCall::doExecute(Environment & env)
{
    SymbolDescPtr desc = env.findGlobal(id_);
    if (desc->getType() != SymbolDescriptor::FUNCTION)
        throw NotFunctionException(id_);
    // obliczanie wartosci funkcji
    ValueList values;
    for_each(expressions_.begin(), expressions_.end(),
            bind(&FunctionCall::calcArg, this, ref(env), _1, ref(values)));
    // wywolanie funkcji
    FuncDescPtr func = static_pointer_cast<FunctionDescriptor>(desc);
    return func->execute(env, values);
}

} /* namespace matryca */
