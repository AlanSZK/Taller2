#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

#include "funciones.h"


using namespace std;

/**
 * Funciones
 */

void saludo(){
    std::cout<<"==========================================="<<std::endl;
    std::cout<<"Taller 2 Computación Paralela y Distribuída"<<std::endl;
    std::cout<<"==========================================="<<std::endl;
    std::cout<<std::endl<<std::endl;
}

void integrantes(){
    std::cout<<"=================="<<std::endl;
    std::cout<<"Integrantes:"<<std::endl;
    std::cout<<"-Alan Slazak"<<std::endl;
    std::cout<<"-Esteban Rojas"<<std::endl;
    std::cout<<"=================="<<std::endl;
}
/*
std::map<int,double> listaPromedios(std::vector<estudiante> estudiantes) //Para obtener una lista de cada id con el promedio calculado
{
    std::map<int, double> lista;
    for (int i=0; i<estudiantes.size();i++)
    {
        lista.insert(std::pair<int, double>(estudiantes.at(i).getId(),estudiantes.at(i).calcularPromedio()));

    }
    return lista;

}
*/
/**Funcion para obtener los datos del archivo
 * y al obtener los datos se eliminan las comillas
 */


std::vector<std::string> obtenerdatos(std::string linea){
    std::vector<std::string> arreglo;
    std::stringstream reem(linea);
    std::string item;
    
    std::string comilla="\"";
    std::string nada="";

    while(getline(reem,item,';')){
        std::string dato=item;
        int pos=dato.find(comilla);
        while(pos != -1){
            dato.replace(pos,comilla.size(),nada);
            pos=dato.find(comilla,pos+nada.size());     
        }
        arreglo.push_back(dato);
    }
    return arreglo;
}

int cantidadVentas (std::vector<producto> productos, std::string fecha)
{
    bool inicioFecha =false;
    int cantidad = 0;

    for(unsigned int i=0;i<productos.size();i++)
    {
        if(productos.at(i).getFecha() == fecha)
        {
            inicioFecha = true;
            cantidad++;

        }
        else if (inicioFecha)
        {
            break;
        }
    }
    return cantidad;
}
