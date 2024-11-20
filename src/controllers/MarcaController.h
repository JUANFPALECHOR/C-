// src/controllers/MarcaController.h
#ifndef MARCACONTROLLER_H
#define MARCACONTROLLER_H

#include <vector>
#include "Marca.h"

class MarcaController {
private:
    std::vector<Marca> marcas;

public:
    // Agregar Marca
    bool agregarMarca(const Marca& marca);

    // Obtener Marca por ID
    Marca* obtenerMarcaPorId(int id);

    // Actualizar Marca
    bool actualizarMarca(int id, const Marca& marcaActualizada);

    // Eliminar Marca
    bool eliminarMarca(int id);

    // Listar todas las Marcas
    std::vector<Marca> listarMarcas() const;
};

#endif // MARCACONTROLLER_H
