/**
 * EnvironmentException.h
 *
 * @class EnvironmentException
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef ENVIRONMENTEXCEPTION_H_
#define ENVIRONMENTEXCEPTION_H_

#include <exception>
#include "../../parser/location.hh"

//TODO usprawnic (dac metode wirtualna additional info i zwracac tutaj "Blad: " +additional info

namespace matryca
{

class EnvironmentException: public std::exception
{
public:
    EnvironmentException():
        captured_(false)
    {
    }

    EnvironmentException(const std::string s) :
            s_(s)
    {

    }

    virtual const char* what() const throw ()
    {
        return "Blad wykonania: \n\t";
    }
    virtual ~EnvironmentException() throw ()
    {
    }
    location loc_;
    // czy wyjatek juz byl wylapany i dodano mu numer pozycje
    bool captured_;
    std::string s_;
};

} /* namespace matryca */
#endif /* ENVIRONMENTEXCEPTION_H_ */
