#include "DetalleFactura.h"

// Constructor
DetalleFactura::DetalleFactura(int idDetalle, int idFact, int idProd, double valor, int cantidad)
    : idDetalleFactura(idDetalle), idFactura(idFact), idProducto(idProd),
      valorProducto(valor), cantidadProductos(cantidad) {
}

// Getters y Setters
int DetalleFactura::getIdDetalleFactura() const {
    return idDetalleFactura;
}

void DetalleFactura::setIdDetalleFactura(int id) {
    idDetalleFactura = id;
}

int DetalleFactura::getIdFactura() const {
    return idFactura;
}

void DetalleFactura::setIdFactura(int id) {
    idFactura = id;
}

int DetalleFactura::getIdProducto() const {
    return idProducto;
}

void DetalleFactura::setIdProducto(int id) {
    idProducto = id;
}

double DetalleFactura::getValorProducto() const {
    return valorProducto;
}

void DetalleFactura::setValorProducto(double valor) {
    valorProducto = valor;
}

int DetalleFactura::getCantidadProductos() const {
    return cantidadProductos;
}

void DetalleFactura::setCantidadProductos(int cantidad) {
    cantidadProductos = cantidad;
}

// Método para calcular el subtotal
double DetalleFactura::calcularSubtotal() const {
    return valorProducto * cantidadProductos;
}
