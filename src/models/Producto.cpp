#include "Producto.h"


Producto::Producto(int id, const std::string& descripcion, int idMarca, double precio)
    : idProducto(id), descripcionProducto(descripcion), idMarca(idMarca), precio(precio) {
}


int Producto::getIdProducto() const {
    return idProducto;
}

void Producto::setIdProducto(int id) {
    idProducto = id;
}

std::string Producto::getDescripcionProducto() const {
    return descripcionProducto;
}

void Producto::setDescripcionProducto(const std::string& descripcion) {
    descripcionProducto = descripcion;
}

int Producto::getIdMarca() const {
    return idMarca;
}

void Producto::setIdMarca(int idMarca) {
    idMarca = idMarca;
}

double Producto::getPrecio() const { 
    return precio;
}

void Producto::setPrecio(double precio) {
    this->precio = precio;
}
