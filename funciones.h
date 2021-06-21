#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <map>

#include "producto.h"





void saludo();
void integrantes();
std::vector<std::string> obtenerdatos(std::string linea);
int cantidadVentas (std::vector<producto> productos, std::string fecha);




#endif