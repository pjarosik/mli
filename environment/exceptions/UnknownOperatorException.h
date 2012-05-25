/**
 * UnknownOperatorException.h
 *
 * @class UnknownOperatorException
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#ifndef UNKNOWNOPERATOREXCEPTION_H_
#define UNKNOWNOPERATOREXCEPTION_H_

#include "EnvironmentException.h"

namespace matryca
{

class UnknownOperatorException : public EnvironmentException
{
public:
    UnknownOperatorException(const std::string &op) :
         op_(op)
    {
    }
    virtual ~UnknownOperatorException() throw ()
    {
    }
    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        std::string w = "Nieprawidlowy operator: "+op_;
        return (i+w).c_str();
    }
    std::string op_;
};

} /* namespace matryca */
#endif /* UNKNOWNOPERATOREXCEPTION_H_ */
