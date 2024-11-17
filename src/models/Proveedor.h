#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include <string>

// Enumeración que define el tipo de cuenta bancaria que un proveedor puede tener
// Puede ser una cuenta de AHORROS o una cuenta CORRIENTE
enum class TipoCuenta { AHORROS, CORRIENTE };

// Definición de la clase Proveedor
// Esta clase representa a un proveedor con su información de contacto y datos bancarios.
class Proveedor {
private:
    // Atributos privados para almacenar la información del proveedor
    int id;                     // Identificador único del proveedor
    std::string rut;            // Número RUT del proveedor (cédula o identificación)
    std::string nombre;         // Nombre completo del proveedor
    std::string direccion;      // Dirección de la empresa o residencia del proveedor
    std::string telefono;       // Número de teléfono del proveedor
    std::string email;          // Correo electrónico del proveedor
    std::string banco;          // Nombre del banco asociado al proveedor
    std::string nroCuenta;      // Número de cuenta bancaria del proveedor
    TipoCuenta tipoCuenta;      // Tipo de cuenta bancaria (AHORROS o CORRIENTE)

public:
    // Constructor de la clase Proveedor
    // Inicializa un objeto Proveedor con todos sus atributos
    // Parámetros:
    // - id: Identificador único del proveedor
    // - rut: Documento de identificación del proveedor
    // - nombre: Nombre completo del proveedor
    // - direccion: Dirección del proveedor
    // - telefono: Número de contacto del proveedor
    // - email: Correo electrónico del proveedor
    // - banco: Nombre del banco asociado al proveedor
    // - nroCuenta: Número de cuenta bancaria
    // - tipoCuenta_: Tipo de cuenta bancaria (AHORROS o CORRIENTE)
    Proveedor(int id, const std::string& rut, const std::string& nombre,
              const std::string& direccion, const std::string& telefono,
              const std::string& email, const std::string& banco,
              const std::string& nroCuenta, TipoCuenta tipoCuenta_);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del proveedor
    int getId() const;

    // Establece un nuevo ID para el proveedor
    void setId(int id_);

    // Obtiene el RUT del proveedor
    std::string getRut() const;

    // Establece un nuevo RUT para el proveedor
    void setRut(const std::string& rut_);

    // Obtiene el nombre del proveedor
    std::string getNombre() const;

    // Establece un nuevo nombre para el proveedor
    void setNombre(const std::string& nombre_);

    // Obtiene la dirección del proveedor
    std::string getDireccion() const;

    // Establece una nueva dirección para el proveedor
    void setDireccion(const std::string& direccion_);

    // Obtiene el número de teléfono del proveedor
    std::string getTelefono() const;

    // Establece un nuevo número de teléfono para el proveedor
    void setTelefono(const std::string& telefono_);

    // Obtiene el email del proveedor
    std::string getEmail() const;

    // Establece un nuevo email para el proveedor
    void setEmail(const std::string& email_);

    // Obtiene el nombre del banco del proveedor
    std::string getBanco() const;

    // Establece un nuevo banco para el proveedor
    void setBanco(const std::string& banco_);

    // Obtiene el número de cuenta bancaria del proveedor
    std::string getNroCuenta() const;

    // Establece un nuevo número de cuenta bancaria
    void setNroCuenta(const std::string& nroCuenta_);

    // Obtiene el tipo de cuenta bancaria (AHORROS o CORRIENTE)
    TipoCuenta getTipoCuenta() const;

    // Establece un nuevo tipo de cuenta bancaria
    void setTipoCuenta(TipoCuenta tipoCuenta_);
};

#endif // PROVEEDOR_H
