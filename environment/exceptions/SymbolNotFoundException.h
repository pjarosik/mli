/**
 * SymbolNotFoundException.h
 *
 * @class SymbolNotFoundException
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef SYMBOLNOTFOUNDEXCEPTION_H_
#define SYMBOLNOTFOUNDEXCEPTION_H_
#include "EnvironmentException.h"

namespace matryca
{

class SymbolNotFoundException : public EnvironmentException
{
public:
    SymbolNotFoundException(const SymbolDescriptor::SymbolID &id) :
        id_(id)
    {
    }
    virtual ~SymbolNotFoundException() throw ()
    {
    }
    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        std::string w = id_ + " nie mogl byc znaleziony.";
        return (i+w).c_str();
    }
    SymbolDescriptor::SymbolID id_;
};

} /* namespace matryca */
#endif /* SYMBOLNOTFOUNDEXCEPTION_H_ */
