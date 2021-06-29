#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>


class producto
{
    private:
        std::string fecha; //Fecha de venta
        int cantidad; //Cantidad total de productos vendidos en alguna fecha.


    public:

        //CONSTRUCTORES
        producto();
        producto(std::string fecha, int cantidad);

       

       
        //GETTERS
        std::string getFecha()
        {
            return this->fecha;
        }
        int getCantidad()
        {
            return this->cantidad;
        }
      

        //SETTERS
        void setFecha(std::string fecha)
        {
            this->fecha = fecha;
        }
        void setCantidad(int cantidad)
        {
            this->cantidad = cantidad;
        }
     



};

#endif