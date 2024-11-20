// Validator.h
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <regex>

class Validator {
public:
    // Validar email
    static bool validarEmail(const std::string& email);

    // Validar teléfono (solo números y longitud específica)
    static bool validarTelefono(const std::string& telefono);

    // Validar RUT (simplificación)
    static bool validarRut(const std::string& rut);

    // Validar números positivos
    static bool esPositivo(int numero);
    static bool esPositivo(double numero);

    // Validar strings no vacíos
    static bool noVacio(const std::string& str);
};

#endif // VALIDATOR_H
