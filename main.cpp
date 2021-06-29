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
#include "venta.h"


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

    std::vector<venta> ventas; //Vector que contiene los productos de la lista extraida del csv.
  
    if (argc>1)
    {
        bool primeraLinea=true;
        bool primeraIgualacion=true;
        int id = 1; //id que se incrementa para guardar ventas;
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
                        venta v (id,fecha,cantidadVentas);
                        ventas.push_back(v);
                        
                        fecha=cortarFecha(strProducto.at(0));
                        cantidadVentas = atoi(strProducto.at(2).c_str());

                        id++;

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

        std::cout<<"ULTIMO DÍA VENTA\n\nFecha:"<<ventas.at(ventas.size()-1).getId()<<"Cantidad:"<<ventas.at(ventas.size()-1).getCantidad()<<std::endl;
        auto end = chrono::system_clock::now();
        chrono::duration<float,milli> duration = end - start;
        std::cout<<duration.count()<<"'ms"<<std::endl;

    }
   
    
   
    return EXIT_SUCCESS;
}

    
   


