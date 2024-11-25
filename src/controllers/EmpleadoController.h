// src/controllers/EmpleadoController.h

#ifndef EMPLEADOCONTROLLER_H
#define EMPLEADOCONTROLLER_H

#include <vector>
#include <memory>
#include "../models/Empleado.h"

class EmpleadoController {
private:
    std::vector<std::shared_ptr<Empleado>> empleados;

public:
    // Agregar un nuevo empleado
    bool agregar(const std::shared_ptr<Empleado>& empleado);

    // Listar todos los empleados
    std::vector<std::shared_ptr<Empleado>> listar() const;

    // Actualizar un empleado por ID
    bool actualizar(int id, const std::shared_ptr<Empleado>& empleadoActualizado);

    // Eliminar un empleado por ID
    bool eliminar(int id);

    // Obtener un empleado por ID
    std::shared_ptr<Empleado> obtenerPorId(int id) const;
};

#endif // EMPLEADOCONTROLLER_H
