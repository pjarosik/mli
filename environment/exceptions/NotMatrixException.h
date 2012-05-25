/**
 * NotMatrixException.h
 *
 * @class NotMatrixException
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#ifndef NOTMATRIXEXCEPTION_H_
#define NOTMATRIXEXCEPTION_H_

#include "EnvironmentException.h"

namespace matryca
{

class NotMatrixException: public EnvironmentException
{
public:
    NotMatrixException()
    {

    }
    virtual ~NotMatrixException() throw ()
    {

    }
    const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        return i.c_str();
    }
};

} /* namespace matryca */
#endif /* NOTMATRIXEXCEPTION_H_ */
