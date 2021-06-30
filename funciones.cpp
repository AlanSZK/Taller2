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
#include "venta.h"



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

int cantidadVentas (std::vector<venta> ventas, std::string fecha)
{
    bool inicioFecha =false;
    int cantidad = 0;

    for(unsigned int i=0;i<ventas.size();i++)
    {
        if(ventas.at(i).getFecha() == fecha)
        {
            inicioFecha = true;
            cantidad+=ventas.at(i).getCantidad();

        }
        else if (inicioFecha)
        {
            break;
        }
    }
    return cantidad;
}

std::string cortarFecha (std::string fecha)
{
    std::string nuevaFecha;

    int pos = fecha.find(" ");

    nuevaFecha = fecha.substr(0, pos);

    return nuevaFecha;
}

void regresionLineal (vector<venta> ventas)
{
    float x,x2,y,xy,a,b;
    int n = ventas.size();
    int dias;
    float prediccion;
    
    for(int i=0;i<n;i++)
    {
        x = x + ventas.at(i).getId();
        x2 = x2 + (ventas.at(i).getId())*(ventas.at(i).getId());
        y = y + ventas.at(i).getCantidad();
        xy = xy + (ventas.at(i).getId() * ventas.at(i).getCantidad());


    }

      b = (n*xy - x*y)/(n*x2 - x*x);
      a = (y - b*x)/n;

      std::cout << "Ecuación de recta generada: y = " << a << " + " << b << "x"<<std::endl;

      std:: cout << " Ingrese número de diás después de última fecha para mostrar cantidad predecida de ventas: ";
      std::fflush(stdin);
      std::cin >> dias;

      prediccion = b + a*(n+dias);

      std:: cout << "Cantidad:" << prediccion << " productos.";

}