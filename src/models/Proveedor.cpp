#include "Proveedor.h"

Proveedor::Proveedor(int id, const std::string& rut, const std::string& nombre,
                   const std::string& direccion, const std::string& telefono,
                   const std::string& email, const std::string& banco,
                   const std::string& nroCuenta, TipoCuenta tipoCuenta)
    : Persona(id, nombre, direccion, telefono, email),
      rut(rut), banco(banco), nroCuenta(nroCuenta), tipoCuenta(tipoCuenta) {}

// Getters
std::string Proveedor::getRut() const {
    return rut;
}

std::string Proveedor::getBanco() const {
    return banco;
}

std::string Proveedor::getNroCuenta() const {
    return nroCuenta;
}

TipoCuenta Proveedor::getTipoCuenta() const {
    return tipoCuenta;
}

// Setters
void Proveedor::setRut(const std::string& rut) {
    this->rut = rut;
}

void Proveedor::setBanco(const std::string& banco) {
    this->banco = banco;
}

void Proveedor::setNroCuenta(const std::string& nroCuenta) {
    this->nroCuenta = nroCuenta;
}

void Proveedor::setTipoCuenta(TipoCuenta tipoCuenta) {
    this->tipoCuenta = tipoCuenta;
}

// Métodos adicionales
std::string Proveedor::tipoCuentaToString() const {
    switch(tipoCuenta) {
        case TipoCuenta::AHORROS:
            return "Ahorros";
        case TipoCuenta::CORRIENTE:
            return "Corriente";
        default:
            return "Desconocido";
    }
}

void Proveedor::mostrarInfo() const {
    Persona::mostrarInfo();
    std::cout << "RUT: " << rut
              << ", Banco: " << banco
              << ", Número de Cuenta: " << nroCuenta
              << ", Tipo de Cuenta: " << tipoCuentaToString() << std::endl;
}
