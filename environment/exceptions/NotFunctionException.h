/**
 * NotFunctionException.h
 *
 * @class NotFunctionException
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef NOTFUNCTIONEXCEPTION_H_
#define NOTFUNCTIONEXCEPTION_H_

#include "EnvironmentException.h"
#include "../descriptor/SymbolDescriptor.h"
namespace matryca
{

class NotFunctionException: public EnvironmentException
{
public:
    NotFunctionException(const SymbolDescriptor::SymbolID &id) :
            id_(id)
    {
    }
    virtual ~NotFunctionException() throw ()
    {
    }
    const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        std::string w = id_+" nie jest funkcja.";
        return (i+w).c_str();
    }
    SymbolDescriptor::SymbolID id_;
};

} /* namespace matryca */
#endif /* NOTFUNCTIONEXCEPTION_H_ */
