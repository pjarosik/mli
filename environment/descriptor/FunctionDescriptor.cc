/**
 * FunctionDescriptor.cc
 *
 * @class FunctionDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#include "FunctionDescriptor.h"
#include "../exceptions/WrongParamsException.h"
#include "../exceptions/SymbolNotFoundException.h"
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>

using namespace boost;
using namespace std;
namespace matryca
{

FunctionDescriptor::FunctionDescriptor()
{

}

FunctionDescriptor::FunctionDescriptor(const SymbolID &id, const IDList &params, const InstructionPtrList &list) :
        id_(id), instructions_(list), params_(params)
{
}

FunctionDescriptor::~FunctionDescriptor()
{
    params_.clear();
    instructions_.clear();
}

Value FunctionDescriptor::execute(Environment &env, const ValueList &values, bool no_stack)
{
    Value value = 0; // zwracana wartosc
    if (!no_stack)
    { // gdy wywolujacy zazadal, zeby nie tworzyc stosu (np dla glownej funkcji programu)
        if (values.size() != params_.size())
            throw new WrongParamsException("Nieprawidlowa liczba paramatrow wywolania funkcji: " + id_);
        createLocalVariables(env, values); // zainicjuj parametry
    }
    for_each(instructions_.begin(), instructions_.end(), bind(&Instruction::execute, _1, ref(env)));
    if (!no_stack)
    {
        try
        {
            VarDescPtr ret_val = static_pointer_cast<VariableDescriptor>(env.findLocal(id_)); // pobranie zwracanej wartosci
            value = ret_val->getValue();
        }
        catch (const SymbolNotFoundException &e)
        {
            // to byla funkcja main, bo jest wywalilo wyjatek o braku
            // zmiennej na stosie lokalnym o nazwie funkcji
            env.out() << "wykonanie glownej funkcji programu zakoczone powodzeniem" << std::endl;
        }
        cleanUp(env);
    }
    return value;
}

FunctionDescriptor::Type FunctionDescriptor::getType() const
{
    return FUNCTION;
}

void FunctionDescriptor::createLocalVariables(Environment &env, const ValueList & init_val)
{
    env.pushSymbolTable(); // dodanie na stos nowej, pustej tablicy symboli
    SymbolDescPtr ret_val = SymbolDescPtr(new VariableDescriptor(id_, RET_VALUE)); // dodanie zmiennej na zwracana wartosc
    env.addLocal(ret_val);
    IDList::iterator id = params_.begin();
    for (ValueList::const_iterator val = init_val.begin(); val != init_val.end() && id != params_.end(); ++val, ++id)
    {
        SymbolDescPtr param = SymbolDescPtr(new VariableDescriptor(*id, *val));
        env.addLocal(param);
    }

}

void FunctionDescriptor::cleanUp(Environment &env)
{
    env.popSymbolTable();
    // TODO na przyszlosc cos moze wiecej
}

FunctionDescriptor::SymbolID FunctionDescriptor::getSymbol() const
{
    return id_;
}

} /* namespace matryca */
