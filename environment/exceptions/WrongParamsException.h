/**
 * WrongParamsException.h
 *
 * @class WrongParamsException
 * @brief Brief description.
 * @author nieznany
 * @date 10-05-2012
 */

#ifndef WRONGPARAMSEXCEPTION_H_
#define WRONGPARAMSEXCEPTION_H_
#include <string>
#include "EnvironmentException.h"

namespace matryca
{

class WrongParamsException : public EnvironmentException
{
public:
    WrongParamsException(const std::string &reason) :
         reason_(reason)
    {
    }
    virtual ~WrongParamsException() throw ()
    {
    }
    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        return (i+reason_).c_str();
    }
    std::string reason_;
};

} /* namespace matryca */
#endif /* WRONGPARAMSEXCEPTION_H_ */
