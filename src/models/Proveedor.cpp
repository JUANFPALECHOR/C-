#include "Proveedor.h"

// Implementación del constructor de la clase Proveedor
// Inicializa todos los atributos utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único del proveedor
// - rut: Número RUT del proveedor (cédula o documento de identificación)
// - nombre: Nombre completo del proveedor
// - direccion: Dirección de la empresa o residencia del proveedor
// - telefono: Número telefónico del proveedor
// - email: Correo electrónico del proveedor
// - banco: Nombre del banco asociado al proveedor
// - nroCuenta: Número de cuenta bancaria del proveedor
// - tipoCuenta_: Tipo de cuenta bancaria (Corriente, Ahorro, etc.)
Proveedor::Proveedor(int id, const std::string& rut, const std::string& nombre,
                     const std::string& direccion, const std::string& telefono,
                     const std::string& email, const std::string& banco,
                     const std::string& nroCuenta, TipoCuenta tipoCuenta_)
    : id(id), rut(rut), nombre(nombre), direccion(direccion),
      telefono(telefono), email(email), banco(banco),
      nroCuenta(nroCuenta), tipoCuenta(tipoCuenta_) {}

// Método para obtener el ID del proveedor
int Proveedor::getId() const {
    return id;
}

// Método para establecer un nuevo ID para el proveedor
void Proveedor::setId(int id_) {
    id = id_;
}

// Método para obtener el RUT del proveedor
std::string Proveedor::getRut() const {
    return rut;
}

// Método para establecer un nuevo RUT para el proveedor
void Proveedor::setRut(const std::string& rut_) {
    rut = rut_;
}

// Método para obtener el nombre del proveedor
std::string Proveedor::getNombre() const {
    return nombre;
}

// Método para establecer un nuevo nombre para el proveedor
void Proveedor::setNombre(const std::string& nombre_) {
    nombre = nombre_;
}

// Método para obtener la dirección del proveedor
std::string Proveedor::getDireccion() const {
    return direccion;
}

// Método para establecer una nueva dirección para el proveedor
void Proveedor::setDireccion(const std::string& direccion_) {
    direccion = direccion_;
}

// Método para obtener el número de teléfono del proveedor
std::string Proveedor::getTelefono() const {
    return telefono;
}

// Método para establecer un nuevo número de teléfono para el proveedor
void Proveedor::setTelefono(const std::string& telefono_) {
    telefono = telefono_;
}

// Método para obtener el email del proveedor
std::string Proveedor::getEmail() const {
    return email;
}

// Método para establecer un nuevo email para el proveedor
void Proveedor::setEmail(const std::string& email_) {
    email = email_;
}

// Método para obtener el nombre del banco del proveedor
std::string Proveedor::getBanco() const {
    return banco;
}

// Método para establecer un nuevo banco para el proveedor
void Proveedor::setBanco(const std::string& banco_) {
    banco = banco_;
}

// Método para obtener el número de cuenta bancaria del proveedor
std::string Proveedor::getNroCuenta() const {
    return nroCuenta;
}

// Método para establecer un nuevo número de cuenta bancaria
void Proveedor::setNroCuenta(const std::string& nroCuenta_) {
    nroCuenta = nroCuenta_;
}

// Método para obtener el tipo de cuenta bancaria del proveedor
TipoCuenta Proveedor::getTipoCuenta() const {
    return tipoCuenta;
}

// Método para establecer un nuevo tipo de cuenta bancaria
void Proveedor::setTipoCuenta(TipoCuenta tipoCuenta_) {
    tipoCuenta = tipoCuenta_;
}
