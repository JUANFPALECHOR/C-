// ProductoController.cpp
#include "ProductoController.h"

bool ProductoController::agregarProducto(const Producto& producto) {
    // Verificar si el ID ya existe
    for (const auto& p : productos) {
        if (p.getIdProducto() == producto.getIdProducto()) {
            return false; // ID duplicado
        }
    }
    productos.push_back(producto);
    return true;
}

Producto* ProductoController::obtenerProductoPorId(int id) {
    for (auto& p : productos) {
        if (p.getIdProducto() == id) {
            return &p;
        }
    }
    return nullptr;
}

bool ProductoController::actualizarProducto(int id, const Producto& productoActualizado) {
    for (auto& p : productos) {
        if (p.getIdProducto() == id) {
            p = productoActualizado;
            return true;
        }
    }
    return false;
}

bool ProductoController::eliminarProducto(int id) {
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        if (it->getIdProducto() == id) {
            productos.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Producto> ProductoController::listarProductos() const {
    return productos;
}
