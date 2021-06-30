#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>

#include "venta.h"




void saludo();
void integrantes();
std::vector<std::string> obtenerdatos(std::string linea);
int cantidadVentas (std::vector<venta> ventas, std::string fecha);
std::string cortarFecha(std::string);

void regresionLineal (std::vector<venta>);
void exponencial (std::vector<venta>);



#endif