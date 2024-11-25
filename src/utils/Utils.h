#ifndef UTILS_H
#define UTILS_H

#include "Factura.h" // Incluir Factura.h para acceder a FechaHora

// Función para verificar si un año es bisiesto
bool esBisiesto(int año);

// Función para verificar si una fecha es válida
bool esFechaValida(const FechaHora& fh);

#endif // UTILS_H
