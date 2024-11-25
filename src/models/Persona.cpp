// src/models/Persona.cpp

#include "Persona.h"

Persona::Persona(int id, const std::string& nombre, const std::string& direccion,
               const std::string& telefono, const std::string& email)
    : id(id), nombre(nombre), direccion(direccion), telefono(telefono), email(email) {}

int Persona::getId() const {
    return id;
}

std::string Persona::getNombre() const {
    return nombre;
}

std::string Persona::getDireccion() const {
    return direccion;
}

std::string Persona::getTelefono() const {
    return telefono;
}

std::string Persona::getEmail() const {
    return email;
}

void Persona::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Persona::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}

void Persona::setTelefono(const std::string& telefono) {
    this->telefono = telefono;
}

void Persona::setEmail(const std::string& email) {
    this->email = email;
}

void Persona::mostrarInfo() const {
    std::cout << "ID: " << id
              << ", Nombre: " << nombre
              << ", Dirección: " << direccion
              << ", Teléfono: " << telefono
              << ", Email: " << email << std::endl;
}
