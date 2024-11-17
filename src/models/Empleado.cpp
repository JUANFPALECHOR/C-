#include "Empleado.h"

// Implementación del constructor de la clase Empleado
// Inicializa todos los atributos utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único del empleado
// - nombre: Nombre completo del empleado
// - direccion: Dirección de residencia del empleado
// - telefono: Número de teléfono del empleado
// - email: Correo electrónico del empleado
// - salario: Salario del empleado
// - horario: Horario de trabajo del empleado
Empleado::Empleado(int id, const std::string& nombre, const std::string& direccion,
                   const std::string& telefono, const std::string& email,
                   double salario, const std::string& horario)
    : id(id), nombre(nombre), direccion(direccion),
      telefono(telefono), email(email), salario(salario), horario(horario) {}

// Método para obtener el ID del empleado
// Retorna el ID como un entero
int Empleado::getId() const {
    return id;
}

// Método para establecer un nuevo ID para el empleado
void Empleado::setId(int id_) {
    id = id_; // Asigna el nuevo ID al atributo 'id'
}

// Método para obtener el nombre del empleado
// Retorna el nombre como un string
std::string Empleado::getNombre() const {
    return nombre;
}

// Método para establecer un nuevo nombre para el empleado
void Empleado::setNombre(const std::string& nombre_) {
    nombre = nombre_; // Asigna el nuevo nombre al atributo 'nombre'
}

// Método para obtener la dirección del empleado
// Retorna la dirección como un string
std::string Empleado::getDireccion() const {
    return direccion;
}

// Método para establecer una nueva dirección para el empleado
void Empleado::setDireccion(const std::string& direccion_) {
    direccion = direccion_; // Asigna la nueva dirección al atributo 'direccion'
}

// Método para obtener el número de teléfono del empleado
// Retorna el número de teléfono como un string
std::string Empleado::getTelefono() const {
    return telefono;
}

// Método para establecer un nuevo número de teléfono para el empleado
void Empleado::setTelefono(const std::string& telefono_) {
    telefono = telefono_; // Asigna el nuevo número de teléfono al atributo 'telefono'
}

// Método para obtener el email del empleado
// Retorna el email como un string
std::string Empleado::getEmail() const {
    return email;
}

// Método para establecer un nuevo email para el empleado
void Empleado::setEmail(const std::string& email_) {
    email = email_; // Asigna el nuevo email al atributo 'email'
}

// Método para obtener el salario del empleado
// Retorna el salario como un double
double Empleado::getSalario() const {
    return salario;
}

// Método para establecer un nuevo salario para el empleado
void Empleado::setSalario(double salario_) {
    salario = salario_; // Asigna el nuevo salario al atributo 'salario'
}

// Método para obtener el horario del empleado
// Retorna el horario como un string
std::string Empleado::getHorario() const {
    return horario;
}

// Método para establecer un nuevo horario para el empleado
void Empleado::setHorario(const std::string& horario_) {
    horario = horario_; // Asigna el nuevo horario al atributo 'horario'
}
