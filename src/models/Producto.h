#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>

// Definición de la clase Producto
class Producto {
private:
    int idProducto;                   // Identificador único del producto
    std::string descripcionProducto;  // Descripción detallada del producto
    int idMarca;                      // Identificador de la marca asociada al producto
    double precio;                    // Precio del producto (nuevo atributo)

public:
    // Constructor
    Producto(int id, const std::string& descripcion, int idMarca, double precio);

    // Getters y Setters
    int getIdProducto() const;
    void setIdProducto(int id);

    std::string getDescripcionProducto() const;
    void setDescripcionProducto(const std::string& descripcion);

    int getIdMarca() const;
    void setIdMarca(int idMarca);

    double getPrecio() const;         // Nuevo getter
    void setPrecio(double precio);    // Nuevo setter
};

#endif // PRODUCTO_H
