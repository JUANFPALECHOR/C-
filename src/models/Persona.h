

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
protected:
    int id;
    std::string nombre;
    std::string direccion;
    std::string telefono;
    std::string email;

public:
    Persona(int id, const std::string& nombre, const std::string& direccion,
            const std::string& telefono, const std::string& email);
    
    // Getters
    int getId() const;
    std::string getNombre() const;
    std::string getDireccion() const;
    std::string getTelefono() const;
    std::string getEmail() const;

    // Setters
    void setNombre(const std::string& nombre);
    void setDireccion(const std::string& direccion);
    void setTelefono(const std::string& telefono);
    void setEmail(const std::string& email);

    // Método virtual para mostrar información
    virtual void mostrarInfo() const;

    // Destructor virtual
    virtual ~Persona() = default;
};

#endif 
