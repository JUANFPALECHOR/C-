// src/models/Empleado.h

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado : public Persona {
private:
    double salario;
    std::string horario;

public:
    Empleado(int id, const std::string& nombre, const std::string& direccion,
             const std::string& telefono, const std::string& email,
             double salario, const std::string& horario);
    
    // Getters
    double getSalario() const;
    std::string getHorario() const;

    // Setters
    void setSalario(double salario);
    void setHorario(const std::string& horario);

    // Método para mostrar información
    void mostrarInfo() const override;
};

#endif // EMPLEADO_H
