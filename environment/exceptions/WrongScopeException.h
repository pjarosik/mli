/**
 * WrongScopeException.h
 *
 * @class WrongScopeException
 * @brief Brief description.
 * @author nieznany
 * @version APP_V.MODULE_V.CLASS_V
 * @date 10-05-2012
 */

#ifndef WRONGSCOPEEXCEPTION_H_
#define WRONGSCOPEEXCEPTION_H_

#include "EnvironmentException.h"

namespace matryca
{

class WrongScopeException : EnvironmentException
{
public:
    WrongScopeException()
    {
    }
    virtual ~WrongScopeException() throw ()
    {
    }
    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        std::string w = "Proba dostepu do zakresu lokalnego w zakresie globalnym";
        return (i+w).c_str();
    }
};

} /* namespace matryca */
#endif /* WRONGSCOPEEXCEPTION_H_ */
