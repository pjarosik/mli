/**
 * MatrycaDriver.cc
 *
 * @class MatrycaDriver
 * @brief Brief description.
 * @author nieznany
 * @date 04-05-2012
 */

#include "Driver.h"
#include "environment/EnvironmentImpl.h"

#include <iostream>

namespace matryca
{

Driver::Driver()
{
}

Driver::ScannerPtr Driver::getScanner()
{
    return scanner_;
}

Driver::EnvironmentPtr Driver::parseStream(std::istream &in, std::ostream &out, std::ostream &err)
{
    Parser parser(*this);
    environment_ = EnvironmentPtr(new EnvironmentImpl(EnvironmentImpl::SymbolTablePtr(new EnvironmentImpl::SymbolTable), out, err));
    scanner_ = ScannerPtr(new Scanner(&in, &out));
    parser.parse();
    // dodanie do srodowiska glownej funkcji programu
    addFunction("_main", IDList(), global_); // pusta lista parametrow
    return environment_;
}

Driver::InstructionPtrList* Driver::getLocalInstructionPtrList()
{
    InstructionPtrList *tmp = new InstructionPtrList(local_.back());
//    std::cout << "rozmiar: " << local_.back().size() << std::endl;
    local_.pop_back();
    return tmp;
}

void Driver::pushLocalInstructionPtrList()
{
    local_.push_back(InstructionPtrList());
}

void Driver::addLocalInstruction(InstructionPtr instruction)
{
    local_.back().push_back(instruction);
}

void Driver::addID(const SymbolID &id)
{
    currentIDs_.push_back(id);
}

Driver::IDList* Driver::getIDList()
{
    IDList *tmp = new IDList(currentIDs_);
    currentIDs_.clear();
    return tmp;
}

void Driver::addExpression(ExpressionPtr expression)
{
    expressions_.back().push_back(expression);
}

void Driver::pushExpressionPtrList()
{
    expressions_.push_back(ExpressionPtrList());
}

Driver::ExpressionPtrList* Driver::getExpressionPtrList()
{
    ExpressionPtrList *tmp = new ExpressionPtrList(expressions_.back());
    expressions_.pop_back();
    return tmp;
}

void Driver::addExpressionList(const ExpressionPtrList &list)
{
    matrix_.back().push_back(list);
}

void Driver::pushExpressionPtrMatrix()
{
    matrix_.push_back(ExpressionPtrMatrix());
}

Driver::ExpressionPtrMatrix* Driver::getExpressionPtrMatrix()
{
    ExpressionPtrMatrix *tmp = new ExpressionPtrMatrix(matrix_.back());
    matrix_.pop_back();
    return tmp;
}

void Driver::addGlobalInstruction(InstructionPtr instruction)
{
    global_.push_back(instruction);
}

// nowa definicja funkcji nadpisuje stara, wiec nie jest sprawdzane, czy
// istnieje juz funkcja o podanej nazwie
void Driver::addFunction(const Environment::SymbolID & id, const IDList &params, const InstructionPtrList &list)
{
    if (environment_)
    {
        SymbolDescriptor::SymbolDescPtr func = SymbolDescriptor::SymbolDescPtr(new FunctionDescriptor(id, params, list));
        environment_->addGlobal(func);
    }
    else
        throw std::runtime_error("Driver: proba dodania funkcji do nieistniejacego srodowiska");
}


Driver::~Driver()
{
}

} /* namespace matryca */
