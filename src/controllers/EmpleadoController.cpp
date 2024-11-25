// src/controllers/EmpleadoController.cpp

#include "EmpleadoController.h"

bool EmpleadoController::agregar(const std::shared_ptr<Empleado>& empleado) {
    // Verificar si ya existe un empleado con el mismo ID
    for(const auto& e : empleados) {
        if(e->getId() == empleado->getId()) {
            return false; // Ya existe
        }
    }
    empleados.push_back(empleado);
    return true;
}

std::vector<std::shared_ptr<Empleado>> EmpleadoController::listar() const {
    return empleados;
}

bool EmpleadoController::actualizar(int id, const std::shared_ptr<Empleado>& empleadoActualizado) {
    for(auto& e : empleados) {
        if(e->getId() == id) {
            e = empleadoActualizado;
            return true;
        }
    }
    return false; // No encontrado
}

bool EmpleadoController::eliminar(int id) {
    for(auto it = empleados.begin(); it != empleados.end(); ++it) {
        if((*it)->getId() == id) {
            empleados.erase(it);
            return true;
        }
    }
    return false; // No encontrado
}

std::shared_ptr<Empleado> EmpleadoController::obtenerPorId(int id) const {
    for(const auto& e : empleados) {
        if(e->getId() == id) {
            return e;
        }
    }
    return nullptr; // No encontrado
}
