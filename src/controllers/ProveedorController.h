// src/controllers/ProveedorController.h

#ifndef PROVEEDORCONTROLLER_H
#define PROVEEDORCONTROLLER_H

#include <vector>
#include <memory>
#include "../models/Proveedor.h"

class ProveedorController {
private:
    // Lista de proveedores utilizando shared_ptr para manejo seguro de memoria
    std::vector<std::shared_ptr<Proveedor>> proveedores;

public:
    // Agregar un nuevo proveedor
    // Parámetro: shared_ptr<Proveedor> que representa el proveedor a agregar
    // Retorna: true si el proveedor se agrega correctamente, false si el ID ya existe
    bool agregar(const std::shared_ptr<Proveedor>& proveedor);

    // Listar todos los proveedores
    // Retorna: un vector de shared_ptr con todos los proveedores
    std::vector<std::shared_ptr<Proveedor>> listar() const;

    // Actualizar un proveedor por ID
    // Parámetros:
    // - id: ID del proveedor a actualizar
    // - proveedorActualizado: shared_ptr con la información actualizada
    // Retorna: true si el proveedor fue actualizado correctamente, false si no se encontró
    bool actualizar(int id, const std::shared_ptr<Proveedor>& proveedorActualizado);

    // Eliminar un proveedor por ID
    // Parámetro: id del proveedor a eliminar
    // Retorna: true si el proveedor fue eliminado, false si no se encontró
    bool eliminar(int id);

    // Obtener un proveedor por ID
    // Parámetro: id del proveedor a buscar
    // Retorna: shared_ptr<Proveedor> si el proveedor es encontrado, nullptr si no existe
    std::shared_ptr<Proveedor> obtenerPorId(int id) const;

    // Método opcional para verificar si un proveedor tiene facturas asociadas
    // Parámetro: id del proveedor
    // Retorna: true si tiene facturas asociadas, false de lo contrario
    bool tieneFacturasAsociadas(int id) const;
};

#endif // PROVEEDORCONTROLLER_H
