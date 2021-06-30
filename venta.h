#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include <string>


class venta
{
    private:
        int id; //Indice de 1 a n
        std::string fecha; //Fecha de venta
        int cantidad; //Cantidad total de productos vendidos en alguna fecha.


    public:

        //CONSTRUCTORES
        venta();
        venta(int id, std::string fecha, int cantidad);

       

       
        //GETTERS
        int getId()
        {
            return this->id;
        }
        std::string getFecha()
        {
            return this->fecha;
        }
        int getCantidad()
        {
            return this->cantidad;
        }
      

        //SETTERS
        void setId(int id)
        {
            this->id = id;
        }
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