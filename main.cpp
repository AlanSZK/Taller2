#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

#include "funciones.h"
#include "producto.h"


using namespace std;

/**
 * @param argc cantidad de argumentos
 * @param argv argumento
 * @return Código de salida del programa
 */

int main (int argc, char** argv)
{

    auto start = chrono::system_clock::now();
    saludo();

    std::vector<producto> productos; //Vector que contiene los productos de la lista extraida del csv.
  
    if (argc>1)
    {
        bool primeraLinea=true;
        
        std::string archivo(argv[1]);
        std::ifstream lectura(archivo);

        std::cout << " Leyendo archivo..." << std::endl;
        if(lectura)
        {
            for (std::string linea; getline(lectura,linea) ;)
            {
                if(primeraLinea==false)
                {
                    std::vector<std::string> strProducto = obtenerdatos(linea);

                    producto p (strProducto.at(0),atol(strProducto.at(1).c_str()),atoi(strProducto.at(2).c_str()), strProducto.at(3));

                    productos.push_back(p);
                }
                else
                    primeraLinea=false;

            }

        }


        
        integrantes();
        auto end = chrono::system_clock::now();
        chrono::duration<float,milli> duration = end - start;
        std::cout<<duration.count()<<"'ms"<<std::endl;

    }

    
   
    return EXIT_SUCCESS;
}

    
   


