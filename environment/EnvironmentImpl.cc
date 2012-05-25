/**
 * InterpreterImpl.cc
 *
 * @class InterpreterImpl
 * @author nieznany
 * @date 06-05-2012
 */

#include "EnvironmentImpl.h"
#include "exceptions/NotFunctionException.h"
#include "descriptor/FunctionDescriptor.h"
#include "descriptor/PrintFunctionDescriptor.h"
#include "exceptions/SymbolNotFoundException.h"
#include "exceptions/WrongScopeException.h"

using namespace boost;

namespace matryca
{

EnvironmentImpl::EnvironmentImpl(SymbolTablePtr global, std::ostream &out, std::ostream &err) :
        global_(global), out_(out), errOut_(err)
{
    addGlobal(FunctionDescriptor::FuncDescPtr(new PrintFunctionDescriptor(out))); // dodanie funkcji wbudowanej do wypisywania wartosci
}

EnvironmentImpl::~EnvironmentImpl()
{
}

void EnvironmentImpl::doExecute(const SymbolID & id) // TODO dodac liste argumentow wywolywanej funkcji
{
    SymbolDescPtr desc = findGlobal(id);
    if (desc->getType() != SymbolDescriptor::FUNCTION)
        throw NotFunctionException(id);
    FunctionDescriptor::FuncDescPtr func = static_pointer_cast<FunctionDescriptor>(desc);
    try
    {
        func->execute(*this, FunctionDescriptor::ValueList(), true); // TODO pusta lista argumentow dla glownej procedury - moznaby dodac parametry main jako globalne (w FunctionDescriptor)
    }
    catch (EnvironmentException& e)
    {
//        errOut_ << "pozycja " << e.loc_ << " -- ";
//        errOut_ << e.what() << std::endl; // FIXME przychodzacy tutaj e nie jest szczegolnym EnvironmentException - nic nie wypisuje e.what() - dlatego przeniesione wypisanie bledu do Exception i Instruction - ale to jest brzydkie (W Exception i Instruction)
        exit(-1); // TODO moze jakies inne zakonczenie
    }
}

void EnvironmentImpl::doAddLocal(SymbolDescPtr desc_ptr)
{
    // nowy symbol zastepuje stary
    if (local_.size() == 0)
        throw WrongScopeException();

    local_.back()->insert(std::make_pair(desc_ptr->getSymbol(), desc_ptr));
//    std::cout << "ustawiono lokalnej " << desc_ptr->getSymbol() << std::endl;
}

EnvironmentImpl::SymbolDescPtr EnvironmentImpl::doFindLocal(const SymbolID & id)
{
    if (local_.size() == 0)
        // pusty stos zakresow - czyli teraz jest zakres globalny
        throw SymbolNotFoundException(id);

    try
    {
        SymbolDescPtr ret = local_.back()->at(id);
//        std::cout << "pobrano lokalna " << id << std::endl;
        return ret;
    }
    catch (const std::out_of_range & e)
    {
        // symbol nie zostal znaleziony
        throw SymbolNotFoundException(id);
    }
}

// nowa definicja funkcji nadpisuje stara
// nowa definicja zmiennej nadpisuje stara
void EnvironmentImpl::doAddGlobal(SymbolDescPtr desc_ptr)
{
    global_->insert(std::make_pair(desc_ptr->getSymbol(), desc_ptr));
//    std::cout << "ustawiono globalnej " << desc_ptr->getSymbol()<< std::endl;
}

EnvironmentImpl::SymbolDescPtr EnvironmentImpl::doFindGlobal(const SymbolID & id)
{
    try
    {
        Environment::SymbolDescPtr s = global_->at(id);
//        std::cout << "znaleziono globalna " << id << std::endl;
        return s;
    }
    catch (const std::out_of_range & e)
    {
        throw SymbolNotFoundException(id);
    }
}

void EnvironmentImpl::doPushSymbolTable()
{
    local_.push_back(SymbolTablePtr(new SymbolTable));
}

void EnvironmentImpl::doPopSymbolTable()
{
    if (local_.size() != 0)
        local_.pop_back();

    else
        throw std::runtime_error("EnvironmentImpl: proba usuniecia elementu z pustego stosu");

}
EnvironmentImpl::SymbolDescPtr EnvironmentImpl::doFind(const SymbolID & id)
{
    try
    {
        // proba odszukania w zakresie lokalnym
        return findLocal(id);
    }
    catch (const SymbolNotFoundException & e)
    {
        // proba odszukania w zakresie lokalnym
        return findGlobal(id);
    }
}

void EnvironmentImpl::doAdd(SymbolDescPtr desc_ptr)
{
    try
    { // proba dodania w zakresie lokalnym
        addLocal(desc_ptr);
    }
    catch (const WrongScopeException &e)
    { // w przeciwnym przypadku proba dodania do zakresu globalnego
        addGlobal(desc_ptr);
    }
}

} /* namespace matryca */
