#include <iostream>
#include <chrono>
#include "funciones.h"


int main (int args, char** argv)
{

    auto start = chrono::system_clock::now();
    saludo();

    integrantes();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration = end - start;
    std::cout<<duration.count()<<"'ms"<<std::endl;

    //dfdkjfdkfj
   
    return EXIT_SUCCESS;
}

    
    return 0;


}