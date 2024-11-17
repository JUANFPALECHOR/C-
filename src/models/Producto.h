#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

// Definición de la clase Producto
// Esta clase representa un producto con su descripción y la marca a la que pertenece.
class Producto {
private:
    // Atributos privados para almacenar la información del producto
    int idProducto;                   // Identificador único del producto
    std::string descripcionProducto;  // Descripción detallada del producto
    int idMarca;                      // Identificador de la marca asociada al producto

public:
    // Constructor de la clase Producto
    // Inicializa un objeto Producto con su ID, descripción y ID de marca
    // Parámetros:
    // - id: Identificador único para el producto
    // - descripcion: Descripción del producto
    // - idMarca: Identificador de la marca a la que pertenece el producto
    Producto(int id, const std::string& descripcion, int idMarca);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del producto
    // Retorna el ID como un entero
    int getIdProducto() const;

    // Establece un nuevo ID para el producto
    // Parámetro:
    // - id: El nuevo ID que se asignará al producto
    void setIdProducto(int id);

    // Obtiene la descripción del producto
    // Retorna la descripción como un string
    std::string getDescripcionProducto() const;

    // Establece una nueva descripción para el producto
    // Parámetro:
    // - descripcion: La nueva descripción que se asignará al producto
    void setDescripcionProducto(const std::string& descripcion);

    // Obtiene el ID de la marca asociada al producto
    // Retorna el ID de la marca como un entero
    int getIdMarca() const;

    // Establece un nuevo ID de marca para el producto
    // Parámetro:
    // - idMarca: El nuevo ID de la marca que se asignará al producto
    void setIdMarca(int idMarca);
};

#endif // PRODUCTO_H
