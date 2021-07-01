#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

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
    std::cout<<std::endl<<std::endl;
    std::cout<<"=================="<<std::endl;
    std::cout<<"Integrantes:"<<std::endl;
    std::cout<<"-Alan Slazak"<<std::endl;
    std::cout<<"-Esteban Rojas"<<std::endl;
    std::cout<<"=================="<<std::endl;
}

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
    int x=0;
    int x2=0;
    int y=0;
    int xy=0;
    double a=0;
    double b=0;
    int n = ventas.size();
    int dias;
    double prediccion;
    for(int i=0;i<n;i++)
    {
        x = x + ventas.at(i).getId();
        x2 = x2 + (ventas.at(i).getId())*(ventas.at(i).getId());
        y = y + ventas.at(i).getCantidad();
        xy = xy + (ventas.at(i).getId() * ventas.at(i).getCantidad());

    }

      b = ((n*xy) - (x*y))/((n*x2) - (x*x));
      a = (y - (b*x))/n;

      std::cout << "Ecuación de recta generada: y = " << a << " + " << b << "x"<<std::endl;

      std:: cout << "Predicción después de x días. Ingrese x: ";
      std::fflush(stdin);
      std::cin >> dias;

      prediccion = b + (a*(n+dias));

      std:: cout << "La predicción es de " << prediccion << " ventas.";

}

void exponencial(vector<venta> ventas){
    int n = ventas.size();
    double x=0, y=0, x2=0, xy=0;
    double a=0,b=0,c=0;
    int dias=0;
    double lny[n];
    for(int i=0; i<n; i++){
        lny[i]=log(ventas.at(i).getCantidad());
    }

    for(int i=0; i<n; i++){
        x = x + ventas.at(i).getId();
        x2 = x2 + (ventas.at(i).getId())*(ventas.at(i).getId());
        y = y + lny[i];
        xy = xy + (ventas.at(i).getId() * lny[i]);
    }

    a=(n*xy - x*y)/(n*x2 -x*x);
    b=(x2*y-x*xy)/(x2*n-x*x);
    c=pow(2.71828,b);


    
    std::cout<<"La función en base a ln(y) es: ln(y)="<<a<<"x +ln"<<b<<std::endl;
    std::cout<<"La exponencial es: y="<<c<<"e^"<<a<<"x"<<std::endl;

    std:: cout << "Predicción después de x días. Ingrese x: ";
    std::fflush(stdin);
    std::cin >> dias;
    int prediccion = c*pow(2.71828,a*dias);
    std::cout<<"La predicción es de "<<prediccion<<" ventas"<<std::endl;


}