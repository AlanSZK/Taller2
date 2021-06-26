#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <stdlib.h>

#include "funciones.h"
#include "producto.h"


using namespace std;

/**
 * @param argc cantidad de argumentos
 * @param argv argumento
 * @return Código de salida del programa
 */

std::string cortarFecha (std::string fecha)
{
    std::string nuevaFecha;

    int pos = fecha.find(" ");

    nuevaFecha = fecha.substr(0, pos);

    return nuevaFecha;
}


int main (int argc, char** argv)
{

    auto start = chrono::system_clock::now();
    saludo();

    std::vector<producto> productos; //Vector que contiene los productos de la lista extraida del csv.
  
    if (argc>1)
    {
        bool primeraLinea=true;
        bool primeraIgualacion=true;
        std::string fecha;

        int cantidadVentas = 0; //Cantidad de ventas en un dia determinado

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

                    if(primeraIgualacion==true)
                    {
                        fecha = cortarFecha(strProducto.at(0)); //Fecha correspondiente a día a contar
                        primeraIgualacion = false;

                    }    
                    
                    if(cortarFecha(strProducto.at(0)) != fecha)
                    {
                        producto p (fecha,cantidadVentas);
                        productos.push_back(p);
                        
                        fecha=cortarFecha(strProducto.at(0));
                        cantidadVentas = atoi(strProducto.at(2).c_str());

                    }
                    else
                    {
                        cantidadVentas+= atoi(strProducto.at(2).c_str());

                    } 
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

    
   


