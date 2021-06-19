#include <iostream>
#include <string>
#include "producto.h"

//CONSTRUCTORES
producto()
{

}

producto(string fecha, long sku, int cantidad, string descripcion)
{
    this->fecha = fecha;
    this->sku = sku;
    this->cantidad = cantidad;
    this->descripcion = descripcion;
}

//GETTERS
string getFecha()
{
    return this->fecha;
}
long getSku()
{
    return this->sku;
}
int getCantidad();
{
    return this->cantidad;
}
string getDescripcion()
{
    return this->descripcion;
}

//SETTERS
void setFecha(string fecha)
{
    this->fecha = fecha;
}
void setSku(long sku)
{
    this->sku = sku;
}
void setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}
void setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}
