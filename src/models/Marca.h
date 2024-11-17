#ifndef MARCA_H
#define MARCA_H

#include <string>

// Definición de la clase Marca
// Esta clase representa una marca con un identificador único y un nombre.
class Marca {
private:
    // Atributos privados para almacenar la información de la marca
    int idMarca;                // Identificador único de la marca
    std::string nombreMarca;    // Nombre de la marca

public:
    // Constructor de la clase Marca
    // Inicializa un objeto Marca con un ID y un nombre
    // Parámetros:
    // - id: Identificador único para la marca
    // - nombre: Nombre de la marca
    Marca(int id, const std::string& nombre);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID de la marca
    // Retorna el ID como un entero
    int getIdMarca() const;

    // Establece un nuevo ID para la marca
    // Parámetro:
    // - id: El nuevo ID que se asignará a la marca
    void setIdMarca(int id);

    // Obtiene el nombre de la marca
    // Retorna el nombre como un string
    std::string getNombreMarca() const;

    // Establece un nuevo nombre para la marca
    // Parámetro:
    // - nombre: El nuevo nombre que se asignará a la marca
    void setNombreMarca(const std::string& nombre);
};

#endif // MARCA_H
