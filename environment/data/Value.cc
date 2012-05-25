/**
 * Value.cc
 *
 * @class Value
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#include "Value.h"
namespace matryca
{
Value::Value()
{
    *this = 0;
}
// TODO dodac tez macierze calkowitoliczbowe
Value::Value(int value)
{
    *this = value;
}

Value::Value(double value)
{
    *this = value;
}

Value::Value(const Matrix &m)
{
    *this = m;
}

Value::Value(const Value &o)
{
    if (this == &o)
        return;
    this->type_ = o.type_;
    this->value_ = o.value_;
}

Value& Value::operator=(Value o)
{
    this->type_ = o.type_;
    this->value_ = o.value_;
    return *this;
}

Value& Value::operator=(int a)
{
    this->type_ = I;
    this->value_ = a;
    return *this;
}

Value& Value::operator=(double a)
{
    this->type_ = D;
    this->value_ = a;
    return *this;
}

Value& Value::operator=(const Matrix &m)
{
    this->type_ = M;
    this->value_ = m;
    return *this;
}

Value::~Value()
{
}

// FIXME brzydko zrobione...
// przeszkadza to, ze np. i*m oraz m*i sa to rozne wolane metody
// a typ musi byc znany w czasie kompilacji
// FIXME najpierw zrobic operatory +=, -=, itd. ale poki co one nie
// sa potrzebne
Value Value::operator+(Value o) const
{
    if (type_ == I)
    {
        int a = boost::get<int>(value_);
        if (o.type_ == I)
            return Value(a + boost::get<int>(o.value_));
        if (o.type_ == D)
            return Value((double)a + boost::get<double>(o.value_));
        if (o.type_ == M)
            throw WrongParamsException("Proba dodania skalaru do macierzy.");
    }
    else if (type_ == D)
    {
        double a = boost::get<double>(value_);
        if (o.type_ == I)
            return Value(a + (double)boost::get<int>(o.value_));
        if (o.type_ == D)
            return Value(a + boost::get<double>(o.value_));
        if (o.type_ == M)
            throw WrongParamsException("Proba dodania skalaru do macierzy.");
    }
    else if (type_ == M)
    {
        Matrix a = boost::get<Matrix>(value_);
        if (o.type_ == M)
        {
            try
            {
                return Value(a + boost::get<Matrix>(o.value_));
            }
            catch (const boost::numeric::ublas::bad_argument &e)
            {
                throw WrongParamsException("Nie zgadzaja sie rozmiary dodawanych macierzy.");
            }
        }
        else
            throw WrongParamsException("Proba dodania skalaru do macierzy.");
    }
    throw std::runtime_error("Value1");
}

Value Value::operator*(Value o) const
{
    if (type_ == I)
    {
        int a = boost::get<int>(value_);
        if (o.type_ == I)
            return Value(a * boost::get<int>(o.value_));
        if (o.type_ == D)
            return Value((double)a * boost::get<double>(o.value_));
        if (o.type_ == M)
            return Value(a * boost::get<Matrix>(o.value_));
    }
    else if (type_ == D)
    {
        double a = boost::get<double>(value_);
        if (o.type_ == I)
            return Value((double)a * boost::get<int>(o.value_));
        if (o.type_ == D)
            return Value(a * boost::get<double>(o.value_));
        if (o.type_ == M)
            return Value(a * boost::get<Matrix>(o.value_));
    }
    else if (type_ == M)
    {
        Matrix m = boost::get<Matrix>(value_);
        if (o.type_ == M)
        {
            try
            {
                return Value(prod(m, boost::get<Matrix>(o.value_)));
            }
            catch (const boost::numeric::ublas::bad_argument &e)
            {
                throw WrongParamsException("Nie zgadzaja sie rozmiary dodawanych macierzy.");
            }
        }
        else throw WrongParamsException("Zla kolejnosc mnozenia macierzy przez skalar.");
    }
    throw std::runtime_error("Value2");
}

Value Value::operator-(Value o) const
{
    return *this + (Value(-1) * o);
}

Value Value::inv() const
{
    if (type_ == I)
        return Value(1 / boost::get<int>(value_));
    if (type_ == D)
        return Value(1.0 / boost::get<double>(value_));
    if (type_ == M)
        throw WrongParamsException("odwracanie macierzy nie zaimplementowane");
    throw std::runtime_error("Value3");
}

Value Value::operator/(Value o) const
{
    return *this * o.inv();
}

bool Value::operator<(Value o)
{
    if (type_ == I)
    {
        int a = boost::get<int>(value_);
        if (o.type_ == I)
            return a < boost::get<int>(o.value_);
        if (o.type_ == D)
            return a < boost::get<double>(o.value_);
        if (o.type_ == M)
            throw WrongParamsException("Nie mozna porownywac macierzy z liczba.");
    }
    else if (type_ == D)
    {
        double a = boost::get<double>(value_);
        if (o.type_ == I)
            return a < boost::get<int>(o.value_);
        if (o.type_ == D)
            return a < boost::get<double>(o.value_);
        if (o.type_ == M)
            throw WrongParamsException("Nie mozna porownywac macierzy z liczba.");
    }
    else if (type_ == M)
    {
        if (o.type_ == I || o.type_ == D)
            throw WrongParamsException("Nie mozna porownywac macierzy z liczba.");
        else
            throw WrongParamsException("Relacja nierownosci dla macierzy jest nieokreslona.");
    }
    throw std::runtime_error("Value4");
}

bool Value::operator==(Value o)
{
    if (type_ == M && o.type_ == M)
        return matricesComp(boost::get<Matrix>(o.value_));
    return !(*this < o) && !(o < *this);
}

bool Value::operator!=(Value o)
{
    return !(*this == o);
}
bool Value::operator<=(Value o)
{
    return *this < o || *this == o;
}

bool Value::operator>=(Value o)
{
    return !(*this < o);
}

bool Value::operator>(Value o)
{
    return !(*this <= o);
}

Value Value::getElement(const Value &row, const Value &column)
{
    if (type_ != M)
        throw NotMatrixException();
    if (row.type_ != I || row.type_ != I)
        throw WrongParamsException("Indeksem macierzy powinna byc liczba calkowita");
    int r = boost::get<int>(row.value_);
    int c = boost::get<int>(column.value_);
    try
    {
        return Value(boost::get<Matrix>(value_)(r, c));
    }
    catch (const boost::numeric::ublas::bad_index &e)
    {
        throw OutOfRangeException(r, c);
    }

}

std::ostream& operator<<(std::ostream &out, const Value& v)
{
    if (v.type_ == Value::I)
        return out << boost::get<int>(v.value_);
    else if (v.type_ == Value::D)
        return out << boost::get<double>(v.value_);
    else if (v.type_ == Value::M)
    {
        Value::Matrix value = boost::get<Value::Matrix>(v.value_);
        for (unsigned i = 0; i < value.size1(); ++i)
        {
            for (unsigned j = 0; j < value.size2(); ++j)
                out << value(i, j) << " ";
            out << std::endl << '\t';
        }
        return out;
    }
    throw std::runtime_error("Value5");
}

bool Value::matricesComp(const Matrix &m)
{
    Matrix m2 = boost::get<Matrix>(value_);
    if (m.size1() != m2.size1() || m.size2() != m.size2())
        throw WrongParamsException("Nie zgadzaja sie rozmiary dodawanych macierzy.");
    for (unsigned i = 0; i < m.size1(); ++i)
    {
        for (unsigned j = 0; j < m.size2(); ++j)
        {
            if (m(i, j) != m2(i, j))
                return false;
        }
    }
    return true;
}

}

