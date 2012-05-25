/**
 * NotVariableException.h
 *
 * @class NotVariableException
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#ifndef NOTVARIABLEEXCEPTION_H_
#define NOTVARIABLEEXCEPTION_H_

#include "EnvironmentException.h"

namespace matryca
{

class NotVariableException: public EnvironmentException
{
public:
    NotVariableException(const SymbolDescriptor::SymbolID &id) :
         id_(id)
    {
    }

    virtual ~NotVariableException() throw ()
    {
    }

    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        std::string w = id_ + " nie jest zmienna.";
        return (i + w).c_str();
    }
    SymbolDescriptor::SymbolID id_;
};

} /* namespace matryca */

#endif /* NOTVARIABLEEXCEPTION_H_ */
