#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>


class producto
{
    private:
        std::string fecha;
        long sku;
        int cantidad;
        std::string descripcion;


    public:

        //CONSTRUCTORES
        producto();
        producto(std::string fecha, long sku, int cantidad, std::string descripcion);

       

       
        //GETTERS
        std::string getFecha()
        {
            return this->fecha;
        }
        long getSku()
        {
            return this->sku;
        }
        int getCantidad()
        {
            return this->cantidad;
        }
        std::string getDescripcion()
        {
            return this->descripcion;
        }

        //SETTERS
        void setFecha(std::string fecha)
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
        void setDescripcion(std::string descripcion)
        {
            this->descripcion = descripcion;
        }



};

#endif