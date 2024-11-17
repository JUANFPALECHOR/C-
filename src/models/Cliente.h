#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

// Enumeración para definir los diferentes tipos de clientes
// TipoCliente puede ser: PENSIONADO, EMPLEADO_PUBLICO, EMPRESARIO, MILITAR
enum class TipoCliente { PENSIONADO, EMPLEADO_PUBLICO, EMPRESARIO, MILITAR };

// Definición de la clase Cliente
class Cliente {
private:
    // Atributos privados para almacenar la información del cliente
    int id;                     // Identificador único del cliente
    std::string rut;            // Número RUT del cliente (por ejemplo, cédula o identificación)
    std::string nombre;         // Nombre completo del cliente
    std::string direccion;      // Dirección de residencia del cliente
    std::string telefono;       // Número de teléfono del cliente
    std::string email;          // Correo electrónico del cliente
    std::string profesion;      // Profesión del cliente
    TipoCliente tipoCliente;    // Tipo de cliente (PENSIONADO, EMPLEADO_PUBLICO, etc.)

public:
    // Constructor para inicializar un objeto Cliente con todos sus atributos
    // Parámetros:
    // - id: Identificador único del cliente
    // - rut: Documento de identificación del cliente
    // - nombre: Nombre completo del cliente
    // - direccion: Dirección del cliente
    // - telefono: Número telefónico del cliente
    // - email: Correo electrónico del cliente
    // - profesion: Profesión del cliente
    // - tipo: Tipo de cliente basado en la enumeración TipoCliente
    Cliente(int id, const std::string& rut, const std::string& nombre,
            const std::string& direccion, const std::string& telefono,
            const std::string& email, const std::string& profesion,
            TipoCliente tipo);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del cliente
    int getId() const;

    // Establece un nuevo ID para el cliente
    void setId(int id_);

    // Obtiene el RUT del cliente
    std::string getRut() const;

    // Establece un nuevo RUT para el cliente
    void setRut(const std::string& rut_);

    // Obtiene el nombre del cliente
    std::string getNombre() const;

    // Establece un nuevo nombre para el cliente
    void setNombre(const std::string& nombre_);

    // Obtiene la dirección del cliente
    std::string getDireccion() const;

    // Establece una nueva dirección para el cliente
    void setDireccion(const std::string& direccion_);

    // Obtiene el número de teléfono del cliente
    std::string getTelefono() const;

    // Establece un nuevo número de teléfono para el cliente
    void setTelefono(const std::string& telefono_);

    // Obtiene el email del cliente
    std::string getEmail() const;

    // Establece un nuevo email para el cliente
    void setEmail(const std::string& email_);

    // Obtiene la profesión del cliente
    std::string getProfesion() const;

    // Establece una nueva profesión para el cliente
    void setProfesion(const std::string& profesion_);

    // Obtiene el tipo de cliente (PENSIONADO, EMPLEADO_PUBLICO, etc.)
    TipoCliente getTipoCliente() const;

    // Establece un nuevo tipo de cliente
    void setTipoCliente(TipoCliente tipo);
};

#endif 
