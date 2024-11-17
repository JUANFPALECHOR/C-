#include "Cliente.h" // Incluimos la definición de la clase Cliente

// Constructor de la clase Cliente
// Inicializa todos los atributos del cliente utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único del cliente
// - rut: Número RUT del cliente (por ejemplo, cédula o documento de identificación)
// - nombre: Nombre completo del cliente
// - direccion: Dirección de residencia o de la empresa del cliente
// - telefono: Número telefónico del cliente
// - email: Correo electrónico del cliente
// - profesion: Profesión o actividad laboral del cliente
// - tipo: Tipo de cliente (puede ser REGULAR, VIP, CORPORATIVO, etc.)
Cliente::Cliente(int id, const std::string& rut, const std::string& nombre,
                 const std::string& direccion, const std::string& telefono,
                 const std::string& email, const std::string& profesion,
                 TipoCliente tipo)
    // Lista de inicialización para asignar valores a los atributos de la clase
    : id(id), rut(rut), nombre(nombre), direccion(direccion),
      telefono(telefono), email(email), profesion(profesion), tipoCliente(tipo) {}

// Método para obtener el ID del cliente
// Retorna el ID como un entero
int Cliente::getId() const {
    return id;
}

// Método para establecer un nuevo ID para el cliente
void Cliente::setId(int id_) {
    id = id_; // Asigna el nuevo ID al atributo 'id'
}

// Método para obtener el RUT del cliente
// Retorna el RUT como un string
std::string Cliente::getRut() const {
    return rut;
}

// Método para establecer un nuevo RUT para el cliente
void Cliente::setRut(const std::string& rut_) {
    rut = rut_; // Asigna el nuevo RUT al atributo 'rut'
}

// Método para obtener el nombre del cliente
// Retorna el nombre como un string
std::string Cliente::getNombre() const {
    return nombre;
}

// Método para establecer un nuevo nombre para el cliente
void Cliente::setNombre(const std::string& nombre_) {
    nombre = nombre_; // Asigna el nuevo nombre al atributo 'nombre'
}

// Método para obtener la dirección del cliente
// Retorna la dirección como un string
std::string Cliente::getDireccion() const {
    return direccion;
}

// Método para establecer una nueva dirección para el cliente
void Cliente::setDireccion(const std::string& direccion_) {
    direccion = direccion_; // Asigna la nueva dirección al atributo 'direccion'
}

// Método para obtener el número de teléfono del cliente
// Retorna el número de teléfono como un string
std::string Cliente::getTelefono() const {
    return telefono;
}

// Método para establecer un nuevo número de teléfono para el cliente
void Cliente::setTelefono(const std::string& telefono_) {
    telefono = telefono_; // Asigna el nuevo número de teléfono al atributo 'telefono'
}

// Método para obtener el email del cliente
// Retorna el email como un string
std::string Cliente::getEmail() const {
    return email;
}

// Método para establecer un nuevo email para el cliente
void Cliente::setEmail(const std::string& email_) {
    email = email_; // Asigna el nuevo email al atributo 'email'
}

// Método para obtener la profesión del cliente
// Retorna la profesión como un string
std::string Cliente::getProfesion() const {
    return profesion;
}

// Método para establecer una nueva profesión para el cliente
void Cliente::setProfesion(const std::string& profesion_) {
    profesion = profesion_; // Asigna la nueva profesión al atributo 'profesion'
}

// Método para obtener el tipo de cliente (por ejemplo, REGULAR, VIP, etc.)
// Retorna el tipo de cliente como un valor de la enumeración TipoCliente
TipoCliente Cliente::getTipoCliente() const {
    return tipoCliente;
}

// Método para establecer un nuevo tipo de cliente
void Cliente::setTipoCliente(TipoCliente tipo) {
    tipoCliente = tipo; // Asigna el nuevo tipo de cliente al atributo 'tipoCliente'
}
