// src/models/Empleado.cpp

#include "Empleado.h"

Empleado::Empleado(int id, const std::string& nombre, const std::string& direccion,
                 const std::string& telefono, const std::string& email,
                 double salario, const std::string& horario)
    : Persona(id, nombre, direccion, telefono, email),
      salario(salario), horario(horario) {}

double Empleado::getSalario() const {
    return salario;
}

std::string Empleado::getHorario() const {
    return horario;
}

void Empleado::setSalario(double salario) {
    this->salario = salario;
}

void Empleado::setHorario(const std::string& horario) {
    this->horario = horario;
}

void Empleado::mostrarInfo() const {
    Persona::mostrarInfo();
    std::cout << "Salario: " << salario
              << ", Horario: " << horario << std::endl;
}
