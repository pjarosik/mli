/**
 * PrintFunctionDescriptor.h
 *
 * @class PrintFunctionDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 10-05-2012
 */
#ifndef PRINTFUNCTIONDESCRIPTOR_H_
#define PRINTFUNCTIONDESCRIPTOR_H_
#include "FunctionDescriptor.h"
#include "../data/Value.h"
#include <iostream>
#include <string>

namespace matryca
{
class PrintFunctionDescriptor : public FunctionDescriptor
{ // dziedziczenie po FunctionDescriptor tylko zeby korzystac z obiektow jak z normalnych funkcji
public:
    typedef FunctionDescriptor::SymbolID SymbolID;
    typedef FunctionDescriptor::ValueList ValueList;
    PrintFunctionDescriptor(std::ostream &out, const SymbolID& id = std::string("print"));
    virtual ~PrintFunctionDescriptor();
    // wypisuje na wyjscie liste wejsciowa, element po elemencie
    // zwraca liczbe elementow listy wejsciowej
    Value execute(Environment &env, const ValueList &list, bool); // 3 param tylko dla KONIECZNEJ zgodnosci z FunctionDescriptor
    SymbolID getSymbol() const;
private:
    void printValue(Value value) const;
    SymbolID id_;
    std::ostream &out_;
};

} /* namespace matryca */
#endif /* PRINTFUNCTIONDESCRIPTOR_H_ */
