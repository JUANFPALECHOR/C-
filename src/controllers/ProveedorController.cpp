

#include "ProveedorController.h"

bool ProveedorController::agregar(const std::shared_ptr<Proveedor>& proveedor) {
    // Verificar si ya existe un proveedor con el mismo ID
    for (const auto& p : proveedores) {
        if (p->getId() == proveedor->getId()) {
            return false; // Ya existe
        }
    }
    proveedores.push_back(proveedor);
    return true;
}

std::vector<std::shared_ptr<Proveedor>> ProveedorController::listar() const {
    return proveedores;
}

bool ProveedorController::actualizar(int id, const std::shared_ptr<Proveedor>& proveedorActualizado) {
    for (auto& p : proveedores) {
        if (p->getId() == id) {
            p = proveedorActualizado; // Actualizar el proveedor
            return true;
        }
    }
    return false; // No encontrado
}

bool ProveedorController::eliminar(int id) {
    for (auto it = proveedores.begin(); it != proveedores.end(); ++it) {
        if ((*it)->getId() == id) {
            proveedores.erase(it);
            return true;
        }
    }
    return false; // No encontrado
}

std::shared_ptr<Proveedor> ProveedorController::obtenerPorId(int id) const {
    for (const auto& p : proveedores) {
        if (p->getId() == id) {
            return p; // Retornar el proveedor encontrado
        }
    }
    return nullptr; // No encontrado
}


