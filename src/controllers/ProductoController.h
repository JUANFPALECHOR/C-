// ProductoController.h
#ifndef PRODUCTOCONTROLLER_H
#define PRODUCTOCONTROLLER_H

#include <vector>
#include "Producto.h"

class ProductoController {
private:
    std::vector<Producto> productos;

public:
    // Agregar Producto
    bool agregarProducto(const Producto& producto);

    // Obtener Producto por ID
    Producto* obtenerProductoPorId(int id);

    // Actualizar Producto
    bool actualizarProducto(int id, const Producto& productoActualizado);

    // Eliminar Producto
    bool eliminarProducto(int id);

    // Listar todos los Productos
    std::vector<Producto> listarProductos() const;
};

#endif // PRODUCTOCONTROLLER_H
