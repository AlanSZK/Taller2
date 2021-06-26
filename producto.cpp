

#include <iostream>
#include <string>
#include "producto.h"

using namespace std;

//CONSTRUCTORES
producto::producto()
{

}

producto::producto(std::string fecha, int cantidad)
{
    this->fecha = fecha;
    this->cantidad = cantidad;
}

