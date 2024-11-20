// src/controllers/MarcaController.cpp
#include "MarcaController.h"

bool MarcaController::agregarMarca(const Marca& marca) {
    // Verificar si el ID ya existe
    for (const auto& m : marcas) {
        if (m.getIdMarca() == marca.getIdMarca()) {
            return false; // ID duplicado
        }
    }
    marcas.push_back(marca);
    return true;
}

Marca* MarcaController::obtenerMarcaPorId(int id) {
    for (auto& m : marcas) {
        if (m.getIdMarca() == id) {
            return &m;
        }
    }
    return nullptr;
}

bool MarcaController::actualizarMarca(int id, const Marca& marcaActualizada) {
    for (auto& m : marcas) {
        if (m.getIdMarca() == id) {
            m = marcaActualizada;
            return true;
        }
    }
    return false;
}

bool MarcaController::eliminarMarca(int id) {
    for (auto it = marcas.begin(); it != marcas.end(); ++it) {
        if (it->getIdMarca() == id) {
            marcas.erase(it);
            return true;
        }
    }
    return false;
}

std::vector<Marca> MarcaController::listarMarcas() const {
    return marcas;
}
