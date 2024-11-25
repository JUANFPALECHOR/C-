// src/controllers/ClienteController.cpp

#include "ClienteController.h"

bool ClienteController::agregar(const std::shared_ptr<Cliente>& cliente) {
    // Verificar si ya existe un cliente con el mismo ID
    for(const auto& c : clientes) {
        if(c->getId() == cliente->getId()) {
            return false; // Ya existe
        }
    }
    clientes.push_back(cliente);
    return true;
}

std::vector<std::shared_ptr<Cliente>> ClienteController::listar() const {
    return clientes;
}

bool ClienteController::actualizar(int id, const std::shared_ptr<Cliente>& clienteActualizado) {
    for(auto& c : clientes) {
        if(c->getId() == id) {
            c = clienteActualizado;
            return true;
        }
    }
    return false; // No encontrado
}

bool ClienteController::eliminar(int id) {
    for(auto it = clientes.begin(); it != clientes.end(); ++it) {
        if((*it)->getId() == id) {
            clientes.erase(it);
            return true;
        }
    }
    return false; // No encontrado
}

std::shared_ptr<Cliente> ClienteController::obtenerPorId(int id) const {
    for(const auto& c : clientes) {
        if(c->getId() == id) {
            return c;
        }
    }
    return nullptr; // No encontrado
}
