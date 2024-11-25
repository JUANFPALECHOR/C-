// src/models/Cliente.cpp

#include "Cliente.h"

Cliente::Cliente(int id, const std::string& rut, const std::string& nombre,
               const std::string& direccion, const std::string& telefono,
               const std::string& email, const std::string& profesion,
               TipoCliente tipoCliente)
    : Persona(id, nombre, direccion, telefono, email),
      rut(rut), profesion(profesion), tipoCliente(tipoCliente) {}

std::string Cliente::getRut() const {
    return rut;
}

std::string Cliente::getProfesion() const {
    return profesion;
}

TipoCliente Cliente::getTipoCliente() const {
    return tipoCliente;
}

void Cliente::setRut(const std::string& rut) {
    this->rut = rut;
}

void Cliente::setProfesion(const std::string& profesion) {
    this->profesion = profesion;
}

void Cliente::setTipoCliente(TipoCliente tipoCliente) {
    this->tipoCliente = tipoCliente;
}

std::string Cliente::tipoClienteToString() const {
    switch(tipoCliente) {
        case TipoCliente::PENSIONADO:
            return "Pensionado";
        case TipoCliente::EMPLEADO_PUBLICO:
            return "Empleado Público";
        case TipoCliente::EMPRESARIO:
            return "Empresario";
        case TipoCliente::MILITAR:
            return "Militar";
        default:
            return "Desconocido";
    }
}

void Cliente::mostrarInfo() const {
    Persona::mostrarInfo();
    std::cout << "RUT: " << rut
              << ", Profesión: " << profesion
              << ", Tipo de Cliente: " << tipoClienteToString() << std::endl;
}
