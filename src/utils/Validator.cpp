// Validator.cpp
#include "Validator.h"

bool Validator::validarEmail(const std::string& email) {
    const std::regex pattern(
        R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)"
    );
    return std::regex_match(email, pattern);
}

bool Validator::validarTelefono(const std::string& telefono) {
    const std::regex pattern(R"(\d{7,15})"); // Ajustar según necesidad
    return std::regex_match(telefono, pattern);
}

bool Validator::validarRut(const std::string& rut) {
    // Simplificación: verificar que tenga al menos 8 caracteres y termine con dígito o K
    if (rut.length() < 8) return false;
    char lastChar = rut.back();
    return (isdigit(lastChar) || lastChar == 'K' || lastChar == 'k');
}

bool Validator::esPositivo(int numero) {
    return numero > 0;
}

bool Validator::esPositivo(double numero) {
    return numero > 0.0;
}

bool Validator::noVacio(const std::string& str) {
    return !str.empty();
}
