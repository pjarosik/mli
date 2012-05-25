/**
 * OutOfRangeException.h
 *
 * @class OutOfRangeException
 * @brief Wyjatek zglaszany, gdy podane indeksy macierzy sa poza zakresem.
 * @author nieznany
 * @date 12-05-2012
 */

#ifndef OUTOFRANGEEXCEPTION_H_
#define OUTOFRANGEEXCEPTION_H_

#include "EnvironmentException.h"
#include <boost/lexical_cast.hpp>
#include <string>

namespace matryca
{

class OutOfRangeException : public EnvironmentException
{
public:
    OutOfRangeException(int row, int column) :
        row_(row), column_(column)
    {
    }
    virtual ~OutOfRangeException() throw ()
    {
    }
    virtual const char* what() const throw ()
    {
        std::string i = EnvironmentException::what();
        return (i + "Indeksy poza zakresem: podane: wiersz: "
                + boost::lexical_cast<std::string>(row_)
                + " kolumna: "+boost::lexical_cast<std::string>(column_)).c_str();
    }
    int row_, column_;
};

} /* namespace matryca */
#endif /* OUTOFRANGEEXCEPTION_H_ */
