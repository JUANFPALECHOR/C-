// src/controllers/ClienteController.h

#ifndef CLIENTECONTROLLER_H
#define CLIENTECONTROLLER_H

#include <vector>
#include <memory>
#include "../models/Cliente.h"

class ClienteController {
private:
    std::vector<std::shared_ptr<Cliente>> clientes;

public:
    // Agregar un nuevo cliente
    bool agregar(const std::shared_ptr<Cliente>& cliente);

    // Listar todos los clientes
    std::vector<std::shared_ptr<Cliente>> listar() const;

    // Actualizar un cliente por ID
    bool actualizar(int id, const std::shared_ptr<Cliente>& clienteActualizado);

    // Eliminar un cliente por ID
    bool eliminar(int id);

    // Obtener un cliente por ID
    std::shared_ptr<Cliente> obtenerPorId(int id) const;
};

#endif // CLIENTECONTROLLER_H
