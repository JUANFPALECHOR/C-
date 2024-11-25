// src/models/Proveedor.h

#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Persona.h"

enum class TipoCuenta {
    AHORROS,
    CORRIENTE
};

class Proveedor : public Persona {
private:
    std::string rut;
    std::string banco;
    std::string nroCuenta;
    TipoCuenta tipoCuenta;

public:
    Proveedor(int id, const std::string& rut, const std::string& nombre,
              const std::string& direccion, const std::string& telefono,
              const std::string& email, const std::string& banco,
              const std::string& nroCuenta, TipoCuenta tipoCuenta);
    
    // Getters
    std::string getRut() const;
    std::string getBanco() const;
    std::string getNroCuenta() const;
    TipoCuenta getTipoCuenta() const;

    // Setters
    void setRut(const std::string& rut); 
    void setBanco(const std::string& banco);
    void setNroCuenta(const std::string& nroCuenta);
    void setTipoCuenta(TipoCuenta tipoCuenta);

    // Método para mostrar información
    void mostrarInfo() const override;

    // Método para convertir TipoCuenta a string
    std::string tipoCuentaToString() const;
};

#endif // PROVEEDOR_H
