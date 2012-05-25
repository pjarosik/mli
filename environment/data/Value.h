/**
 * Value.h
 *
 * @class Value
 * @brief Brief description.
 * @author nieznany
 * @date 11-05-2012
 */

#ifndef VALUE_H_
#define VALUE_H_

#include <boost/variant.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "../exceptions/WrongParamsException.h"
#include "../exceptions/NotMatrixException.h"
#include "../exceptions/OutOfRangeException.h"

#include <iostream>

namespace matryca
{

class Value
{
public:
    enum Type
    {
        I, D, M
    };
    typedef boost::numeric::ublas::matrix<double> Matrix;

    Value();
    // TODO dodac tez macierze calkowitoliczbowe
    Value(int value);
    Value(double value);
    Value(const Matrix &m);
    Value(const Value &o);

    Value& operator=(Value o);
    Value& operator=(int a);
    Value& operator=(double a);
    Value& operator=(const Matrix &m);

    operator double()
    {
        if (type_ == D)
            return boost::get<double>(value_);
        else if (type_ == I)
            return boost::get<int>(value_);
        throw WrongParamsException("Macierz nie moze stac sie skalarem");
    }

    virtual ~Value();

    Value operator+(Value o) const;
    Value operator*(Value o) const;
    Value operator-(Value o) const;
    Value inv() const;
    Value operator/(Value o) const;
    bool operator<(Value o);
    bool operator==(Value o);
    bool operator!=(Value o);
    bool operator<=(Value o);
    bool operator>=(Value o);
    bool operator>(Value o);

    Type getType() const
    {
        return type_;
    }

    Value getElement(const Value &row, const Value &column);

    friend std::ostream& operator<<(std::ostream &out, const Value& v);
private:
    bool matricesComp(const Matrix &m);
    boost::variant<int, double, Matrix> value_;
    Type type_;
};
std::ostream& operator<<(std::ostream &out, const Value& v);
} /* namespace matryca */
#endif /* VALUE_H_ */
