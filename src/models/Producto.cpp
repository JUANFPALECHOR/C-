// Producto.cpp
#include "Producto.h"

// Implementación del constructor de la clase Producto
// Inicializa los atributos de la clase utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único del producto
// - descripcion: Descripción detallada del producto
// - idMarca: Identificador de la marca asociada al producto
Producto::Producto(int id, const std::string& descripcion, int idMarca)
    : idProducto(id), descripcionProducto(descripcion), idMarca(idMarca) {}

// Método para obtener el ID del producto
// Retorna el ID como un entero
int Producto::getIdProducto() const {
    return idProducto;
}

// Método para establecer un nuevo ID para el producto
// Parámetro:
// - id: El nuevo ID que se asignará al producto
void Producto::setIdProducto(int id) {
    idProducto = id; // Asigna el nuevo ID al atributo 'idProducto'
}

// Método para obtener la descripción del producto
// Retorna la descripción como un string
std::string Producto::getDescripcionProducto() const {
    return descripcionProducto;
}

// Método para establecer una nueva descripción para el producto
// Parámetro:
// - descripcion: La nueva descripción que se asignará al producto
void Producto::setDescripcionProducto(const std::string& descripcion) {
    descripcionProducto = descripcion; // Asigna la nueva descripción al atributo 'descripcionProducto'
}

// Método para obtener el ID de la marca asociada al producto
// Retorna el ID de la marca como un entero
int Producto::getIdMarca() const {
    return idMarca;
}

// Método para establecer un nuevo ID de marca para el producto
// Parámetro:
// - idMarca_: El nuevo ID de la marca que se asignará al producto
void Producto::setIdMarca(int idMarca_) {
    idMarca = idMarca_; // Asigna el nuevo ID de la marca al atributo 'idMarca'
}
