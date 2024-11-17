#include "Stock.h"

// Implementación del constructor de la clase Stock
// Inicializa todos los atributos utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único del registro de stock
// - idProd: Identificador del producto en el inventario
// - exist: Cantidad actual de existencias del producto en el inventario
// - stockMin: Nivel mínimo de stock permitido para el producto
Stock::Stock(int id, int idProd, int exist, int stockMin)
    : idStock(id), idProducto(idProd), existencias(exist), stockMinimo(stockMin) {}

// Método para obtener el ID del registro de stock
// Retorna el ID como un entero
int Stock::getIdStock() const {
    return idStock;
}

// Método para establecer un nuevo ID para el registro de stock
void Stock::setIdStock(int id) {
    idStock = id; // Asigna el nuevo ID al atributo 'idStock'
}

// Método para obtener el ID del producto asociado en el inventario
// Retorna el ID del producto como un entero
int Stock::getIdProducto() const {
    return idProducto;
}

// Método para establecer un nuevo ID para el producto asociado
void Stock::setIdProducto(int id) {
    idProducto = id; // Asigna el nuevo ID al atributo 'idProducto'
}

// Método para obtener la cantidad actual de existencias en el inventario
// Retorna el número de existencias como un entero
int Stock::getExistencias() const {
    return existencias;
}

// Método para establecer una nueva cantidad de existencias
void Stock::setExistencias(int exist) {
    existencias = exist; // Asigna la nueva cantidad al atributo 'existencias'
}

// Método para obtener el nivel mínimo de stock permitido
// Retorna el stock mínimo como un entero
int Stock::getStockMinimo() const {
    return stockMinimo;
}

// Método para establecer un nuevo nivel mínimo de stock
void Stock::setStockMinimo(int stockMin) {
    stockMinimo = stockMin; // Asigna el nuevo nivel mínimo al atributo 'stockMinimo'
}
