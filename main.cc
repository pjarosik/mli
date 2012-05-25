#include "Driver.h"
#include <iostream>
#include <fstream>
#include "environment/EnvironmentImpl.h"
#include "environment/data/Value.h"

using namespace matryca;
using namespace std;
using namespace boost;
using namespace boost::numeric::ublas;


int main(int argc, char **argv)
{
    matryca::Driver driver;
    Environment::EnvironmentPtr ptr;
    std::cout << "Interpreter jezyka matryca -- Piotr Jarosik, 2012" << std::endl << std::endl;
    if(argc >= 2) {
        ifstream istr(argv[1], ifstream::in);
        ptr = driver.parseStream(istr, std::cout, std::cerr);
    }
    else
    {
        std::cout << "pobieranie danych ze strumienia wejsciowego:" << std::endl;
        ptr = driver.parseStream(cin, std::cout, std::cerr);
    }
    ptr->execute("_main");
}
