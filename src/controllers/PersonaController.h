// src/controllers/PersonaController.h
#ifndef PERSONACONTROLLER_H
#define PERSONACONTROLLER_H

#include <vector>
#include <memory>
#include "Persona.h"

template <typename T>
class PersonaController {
protected:
    std::vector<std::shared_ptr<T>> personas;

public:
    // Agregar Persona
    virtual bool agregar(const std::shared_ptr<T>& persona) {
        // Verificar si el ID ya existe
        for (const auto& p : personas) {
            if (p->getId() == persona->getId()) {
                return false; // ID duplicado
            }
        }
        personas.push_back(persona);
        return true;
    }

    // Obtener Persona por ID
    virtual std::shared_ptr<T> obtenerPorId(int id) const {
        for (const auto& p : personas) {
            if (p->getId() == id) {
                return p;
            }
        }
        return nullptr;
    }

    // Actualizar Persona
    virtual bool actualizar(int id, const std::shared_ptr<T>& personaActualizada) {
        for (auto& p : personas) {
            if (p->getId() == id) {
                p = personaActualizada;
                return true;
            }
        }
        return false;
    }

    // Eliminar Persona
    virtual bool eliminar(int id) {
        for (auto it = personas.begin(); it != personas.end(); ++it) {
            if ((*it)->getId() == id) {
                personas.erase(it);
                return true;
            }
        }
        return false;
    }

    // Listar todas las Personas
    virtual std::vector<std::shared_ptr<T>> listar() const {
        return personas;
    }
};

#endif // PERSONACONTROLLER_H
