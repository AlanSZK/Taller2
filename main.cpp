#include <iostream>
#include <chrono>
#include "funciones.h"
#include "producto.h"


int main (int args, char** argv)
{

    auto start = chrono::system_clock::now();
    saludo();

    integrantes();
    auto end = chrono::system_clock::now();
    chrono::duration<float,milli> duration = end - start;
    std::cout<<duration.count()<<"'ms"<<std::endl;

    
   
    return EXIT_SUCCESS;
}

    
    return 0;


}