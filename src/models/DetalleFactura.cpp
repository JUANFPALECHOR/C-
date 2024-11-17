#include "DetalleFactura.h"

// Constructor de la clase DetalleFactura
// Inicializa todos los atributos de la clase utilizando una lista de inicialización
// Parámetros:
// - idDetalle: Identificador único del detalle de la factura
// - idFact: Identificador de la factura a la que pertenece este detalle
// - idProd: Identificador del producto incluido en la factura
// - valor: Precio unitario del producto
// - cantidad: Cantidad de unidades del producto incluidas en la factura
DetalleFactura::DetalleFactura(int idDetalle, int idFact, int idProd, double valor, int cantidad)
    : idDetalleFactura(idDetalle), idFactura(idFact), idProducto(idProd),
      valorProducto(valor), cantidadProductos(cantidad) {}

// Método para obtener el ID del detalle de la factura
// Retorna el ID como un entero
int DetalleFactura::getIdDetalleFactura() const {
    return idDetalleFactura;
}

// Método para establecer un nuevo ID para el detalle de la factura
void DetalleFactura::setIdDetalleFactura(int id) {
    idDetalleFactura = id; // Asigna el nuevo ID al atributo 'idDetalleFactura'
}

// Método para obtener el ID de la factura asociada
// Retorna el ID de la factura como un entero
int DetalleFactura::getIdFactura() const {
    return idFactura;
}

// Método para establecer un nuevo ID de la factura
void DetalleFactura::setIdFactura(int id) {
    idFactura = id; // Asigna el nuevo ID de la factura al atributo 'idFactura'
}

// Método para obtener el ID del producto
// Retorna el ID del producto como un entero
int DetalleFactura::getIdProducto() const {
    return idProducto;
}

// Método para establecer un nuevo ID para el producto
void DetalleFactura::setIdProducto(int id) {
    idProducto = id; // Asigna el nuevo ID al atributo 'idProducto'
}

// Método para obtener el valor unitario del producto
// Retorna el precio del producto como un double
double DetalleFactura::getValorProducto() const {
    return valorProducto;
}

// Método para establecer un nuevo valor unitario para el producto
void DetalleFactura::setValorProducto(double valor) {
    valorProducto = valor; // Asigna el nuevo valor al atributo 'valorProducto'
}

// Método para obtener la cantidad de productos
// Retorna la cantidad de unidades del producto como un entero
int DetalleFactura::getCantidadProductos() const {
    return cantidadProductos;
}

// Método para establecer una nueva cantidad de productos
void DetalleFactura::setCantidadProductos(int cantidad) {
    cantidadProductos = cantidad; // Asigna la nueva cantidad al atributo 'cantidadProductos'
}
