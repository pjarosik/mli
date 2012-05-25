/**
 * PrintFunctionDescriptor.cc
 *
 * @class PrintFunctionDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 10-05-2012
 */

#include "PrintFunctionDescriptor.h"
#include <boost/bind.hpp>
#include <iostream>

using namespace std;
using namespace boost;
namespace matryca
{

PrintFunctionDescriptor::PrintFunctionDescriptor(ostream &out, const SymbolID& id) :
        out_(out), id_(id)
{
}

PrintFunctionDescriptor::~PrintFunctionDescriptor()
{
}

Value PrintFunctionDescriptor::execute(Environment & env, const ValueList & list, bool)
{
    std::cout << "print: " << std::endl;
    for_each(list.begin(), list.end(), bind(&PrintFunctionDescriptor::printValue, this, _1));
    return Value((int)(list.size())); //
}

void PrintFunctionDescriptor::printValue(Value value) const
{
    out_ << "\t" << value << std::endl;
}

PrintFunctionDescriptor::SymbolID PrintFunctionDescriptor::getSymbol() const
{
    return id_;
}

} /* namespace matryca */
