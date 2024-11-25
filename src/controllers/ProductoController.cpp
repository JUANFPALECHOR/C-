// ProductoController.cpp
#include "ProductoController.h"
#include <iostream>

// Implementación de los métodos existentes...

bool ProductoController::agregarProducto(const Producto& producto) {
    // Verificar si el ID ya existe
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
            return &p; // Retornar dirección del objeto Producto
        }
    }
    return nullptr;
}

bool ProductoController::actualizarProducto(int id, const Producto& productoActualizado) {
    for (auto& p : productos) {
        if (p.getIdProducto() == id) {
            p = productoActualizado; // Asignar nuevo objeto Producto
            return true;
        }
    }
    return false;
}

bool ProductoController::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getIdProducto() == id) {
            productos.erase(it); // Eliminar objeto Producto
            return true;
        }
    }
    return false;
}

std::vector<Producto> ProductoController::listarProductos() const {
    return productos; // Retornar copia del vector de Productos
}

// Definición del Nuevo Método: Obtener Productos por Marca
std::vector<Producto> ProductoController::obtenerProductosPorMarca(int idMarca) const {
    std::vector<Producto> productosFiltrados;
    for (const auto& producto : productos) { // Iterar sobre objetos Producto
        if (producto.getIdMarca() == idMarca) { // Usar . en lugar de ->
            productosFiltrados.push_back(producto); // Agregar objeto Producto
        }
    }
    return productosFiltrados;
}
