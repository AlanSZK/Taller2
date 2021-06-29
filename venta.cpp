

#include <iostream>
#include <string>
#include "venta.h"

using namespace std;

//CONSTRUCTORES
venta::venta()
{

}

venta::venta(int id, std::string fecha, int cantidad)
{
    this->id = id;
    this->fecha = fecha;
    this->cantidad = cantidad;
}

