#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

// Definición de la clase Empleado
// Esta clase representa un empleado, con atributos como nombre, dirección, salario, entre otros.
class Empleado {
private:
    // Atributos privados para almacenar la información del empleado
    int id;                     // Identificador único del empleado
    std::string nombre;         // Nombre completo del empleado
    std::string direccion;      // Dirección de residencia del empleado
    std::string telefono;       // Número de teléfono del empleado
    std::string email;          // Correo electrónico del empleado
    double salario;             // Salario del empleado
    std::string horario;        // Horario de trabajo del empleado

public:
    // Constructor de la clase Empleado
    // Inicializa un objeto Empleado con todos sus atributos
    // Parámetros:
    // - id: Identificador único para el empleado
    // - nombre: Nombre completo del empleado
    // - direccion: Dirección de residencia del empleado
    // - telefono: Número de contacto del empleado
    // - email: Correo electrónico del empleado
    // - salario: Salario mensual del empleado
    // - horario: Horario de trabajo del empleado
    Empleado(int id, const std::string& nombre, const std::string& direccion,
             const std::string& telefono, const std::string& email,
             double salario, const std::string& horario);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del empleado
    int getId() const;

    // Establece un nuevo ID para el empleado
    void setId(int id_);

    // Obtiene el nombre del empleado
    std::string getNombre() const;

    // Establece un nuevo nombre para el empleado
    void setNombre(const std::string& nombre_);

    // Obtiene la dirección del empleado
    std::string getDireccion() const;

    // Establece una nueva dirección para el empleado
    void setDireccion(const std::string& direccion_);

    // Obtiene el número de teléfono del empleado
    std::string getTelefono() const;

    // Establece un nuevo número de teléfono para el empleado
    void setTelefono(const std::string& telefono_);

    // Obtiene el email del empleado
    std::string getEmail() const;

    // Establece un nuevo email para el empleado
    void setEmail(const std::string& email_);

    // Obtiene el salario del empleado
    double getSalario() const;

    // Establece un nuevo salario para el empleado
    void setSalario(double salario_);

    // Obtiene el horario del empleado
    std::string getHorario() const;

    // Establece un nuevo horario para el empleado
    void setHorario(const std::string& horario_);
};

#endif // EMPLEADO_H
