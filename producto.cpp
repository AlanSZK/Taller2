#include <iostream>
#include <string>
#include "producto.h"

using namespace std;

//CONSTRUCTORES
producto::producto()
{

}

producto::producto(std::string fecha, long sku, int cantidad, std::string descripcion)
{
    this->fecha = fecha;
    this->sku = sku;
    this->cantidad = cantidad;
    this->descripcion = descripcion;
}

