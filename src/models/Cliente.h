// src/models/Cliente.h

#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

enum class TipoCliente {
    PENSIONADO,
    EMPLEADO_PUBLICO,
    EMPRESARIO,
    MILITAR
};

class Cliente : public Persona {
private:
    std::string rut;
    std::string profesion;
    TipoCliente tipoCliente;

public:
    Cliente(int id, const std::string& rut, const std::string& nombre,
            const std::string& direccion, const std::string& telefono,
            const std::string& email, const std::string& profesion,
            TipoCliente tipoCliente);
    
    // Getters
    std::string getRut() const;
    std::string getProfesion() const;
    TipoCliente getTipoCliente() const;

    // Setters
    void setRut(const std::string& rut);
    void setProfesion(const std::string& profesion);
    void setTipoCliente(TipoCliente tipoCliente);

    // Método para mostrar información
    void mostrarInfo() const override;

    // Método para convertir TipoCliente a string
    std::string tipoClienteToString() const;
};

#endif // CLIENTE_H
