#include "Marca.h"

// Implementación del constructor de la clase Marca
// Inicializa los atributos de la clase utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único para la marca
// - nombre: Nombre de la marca
Marca::Marca(int id, const std::string& nombre)
    : idMarca(id), nombreMarca(nombre) {}

// Método para obtener el ID de la marca
// Retorna el ID como un entero
int Marca::getIdMarca() const {
    return idMarca;
}

// Método para establecer un nuevo ID para la marca
// Parámetro:
// - id: El nuevo ID que se asignará a la marca
void Marca::setIdMarca(int id) {
    idMarca = id; // Asigna el nuevo ID al atributo 'idMarca'
}

// Método para obtener el nombre de la marca
// Retorna el nombre como un string
std::string Marca::getNombreMarca() const {
    return nombreMarca;
}

// Método para establecer un nuevo nombre para la marca
// Parámetro:
// - nombre: El nuevo nombre que se asignará a la marca
void Marca::setNombreMarca(const std::string& nombre) {
    nombreMarca = nombre; // Asigna el nuevo nombre al atributo 'nombreMarca'
}
