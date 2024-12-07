
#include "ProductoController.h"
#include <iostream>



bool ProductoController::agregarProducto(const Producto& producto) {
    
    for (const auto& p : productos) {
        if (p.getIdProducto() == producto.getIdProducto()) {
            return false; // ID duplicado
        }
    }
    productos.push_back(producto); // Agregar objeto Producto
    return true;
}

Producto* ProductoController::obtenerProductoPorId(int id) {
    for (auto& p : productos) {
        if (p.getIdProducto() == id) {
            return &p; // Retorna dirección del objeto Producto
        }
    }
    return nullptr;
}

bool ProductoController::actualizarProducto(int id, const Producto& productoActualizado) {
    for (auto& p : productos) {
        if (p.getIdProducto() == id) {
            p = productoActualizado; // Asigna nuevo objeto Producto
            return true;
        }
    }
    return false;
}

bool ProductoController::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getIdProducto() == id) {
            productos.erase(it); // Elimina objeto Producto
            return true;
        }
    }
    return false;
}

std::vector<Producto> ProductoController::listarProductos() const {
    return productos; // Retorna copia del vector de Productos
}


std::vector<Producto> ProductoController::obtenerProductosPorMarca(int idMarca) const {
    std::vector<Producto> productosFiltrados;
    for (const auto& producto : productos) { // Iterar sobre objetos Producto
        if (producto.getIdMarca() == idMarca) { // Usar . en lugar de ->
            productosFiltrados.push_back(producto); // Agregar objeto Producto
        }
    }
    return productosFiltrados;
}
