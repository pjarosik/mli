/**
 * MatrixExpression.cc
 *
 * @class MatrixExpression
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#include "MatrixExpression.h"
#include "../data/Value.h"
#include "../exceptions/WrongParamsException.h"

namespace matryca
{

MatrixExpression::MatrixExpression(const ExpressionPtrMatrix & matrix) :
        matrix_(matrix)
{
    // TODO tu moznaby juz sprawdzac, czy macierz jest prawidlowych rozmiarow
    // ale wtedy rzucany bylby wyjatek w momencie tworzenia obiektu... - wyciek pamieci
    // bo bison pozwala trzymac tylko wskazniki na obiekty
}

MatrixExpression::~MatrixExpression()
{
}

Value MatrixExpression::doExecute(Environment & env)
{
    int i = 0, j = 0;
    if (matrix_.size() == 0)
        throw WrongParamsException("Pusta macierz wyrazen.");
    size_t row_size = matrix_.begin()->size();
    if (row_size == 0)
        throw WrongParamsException("Zle wymiary macierzy.");
    Value::Matrix m(matrix_.size(), row_size);
    for (ExpressionPtrMatrix::iterator it = matrix_.begin(); it != matrix_.end(); ++it, ++i)
    { // kolejne wiersze
        if (it->size() == 0 || it->size() != row_size)
            throw WrongParamsException("Zle wymiary macierzy.");
        else
        {
            j = 0;
            for(ExpressionPtrList::iterator jt = it->begin(); jt != it->end(); ++jt, ++j)
            { // kolejne kolumny wiersza
                Value val = (*jt)->execute(env);
                if(val.getType() == Value::M)
                    throw WrongParamsException("Macierz nie moze byc elementem macierzy");
                m(i, j) = (double)val;
            }
        }
    }
    return Value(m);
}

} /* namespace matryca */
