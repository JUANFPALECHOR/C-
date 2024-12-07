
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <regex>

class Validator {
public:
    
    static bool validarEmail(const std::string& email);

    
    static bool validarTelefono(const std::string& telefono);

    
    static bool validarRut(const std::string& rut);

    
    static bool esPositivo(int numero);
    static bool esPositivo(double numero);

    
    static bool noVacio(const std::string& str);
};

#endif 
