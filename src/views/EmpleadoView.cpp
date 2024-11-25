#include "EmpleadoView.h"
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

EmpleadoView::EmpleadoView(EmpleadoController& empleadoCtrl)
    : empleadoCtrl(empleadoCtrl) {}

void EmpleadoView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Empleados ---\n";
        cout << "1. Agregar Empleado\n";
        cout << "2. Listar Empleados\n";
        cout << "3. Actualizar Empleado\n";
        cout << "4. Eliminar Empleado\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                listarEmpleados();
                break;
            case 3:
                actualizarEmpleado();
                break;
            case 4:
                eliminarEmpleado();
                break;
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while (opcion != 5);
}

void EmpleadoView::agregarEmpleado() {
    int id;
    string nombre, direccion, telefono, email;
    double salario;
    string horario;

    cout << "Ingrese el ID del empleado: ";
    cin >> id;

    if (empleadoCtrl.obtenerPorId(id) != nullptr) {
        cout << "Error: Ya existe un empleado con el ID " << id << ".\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el nombre del empleado: ";
    getline(cin, nombre);

    cout << "Ingrese la dirección del empleado: ";
    getline(cin, direccion);

    cout << "Ingrese el teléfono del empleado: ";
    getline(cin, telefono);

    cout << "Ingrese el email del empleado: ";
    getline(cin, email);

    cout << "Ingrese el salario del empleado: ";
    cin >> salario;

    if (cin.fail() || salario < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Salario inválido.\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el horario del empleado: ";
    getline(cin, horario);

    // Crear un nuevo empleado
    shared_ptr<Empleado> nuevoEmpleado = make_shared<Empleado>(
        id, nombre, direccion, telefono, email, salario, horario);

    if (empleadoCtrl.agregar(nuevoEmpleado)) {
        cout << "Empleado agregado exitosamente.\n";
    } else {
        cout << "Error: No se pudo agregar el empleado.\n";
    }
}

void EmpleadoView::listarEmpleados() {
    vector<shared_ptr<Empleado>> empleados = empleadoCtrl.listar();
    if (empleados.empty()) {
        cout << "No hay empleados registrados.\n";
    } else {
        cout << "\nLista de Empleados:\n";
        cout << "ID\tNombre\tSalario\tHorario\n";
        for (const auto& e : empleados) {
            cout << e->getId() << "\t" << e->getNombre() << "\t" 
                 << e->getSalario() << "\t" << e->getHorario() << "\n";
        }
    }
}

void EmpleadoView::actualizarEmpleado() {
    int id;
    cout << "Ingrese el ID del empleado a actualizar: ";
    cin >> id;

    shared_ptr<Empleado> empleado = empleadoCtrl.obtenerPorId(id);
    if (empleado == nullptr) {
        cout << "Error: No existe un empleado con el ID " << id << ".\n";
        return;
    }

    string nombre, direccion, telefono, email;
    double salario;
    string horario;

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el nuevo nombre del empleado (actual: " << empleado->getNombre() << "): ";
    getline(cin, nombre);

    cout << "Ingrese la nueva dirección del empleado (actual: " << empleado->getDireccion() << "): ";
    getline(cin, direccion);

    cout << "Ingrese el nuevo teléfono del empleado (actual: " << empleado->getTelefono() << "): ";
    getline(cin, telefono);

    cout << "Ingrese el nuevo email del empleado (actual: " << empleado->getEmail() << "): ";
    getline(cin, email);

    cout << "Ingrese el nuevo salario del empleado (actual: " << empleado->getSalario() << "): ";
    cin >> salario;

    if (cin.fail() || salario < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Salario inválido.\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el nuevo horario del empleado (actual: " << empleado->getHorario() << "): ";
    getline(cin, horario);

    // Actualizar los datos del empleado
    empleado->setNombre(nombre);
    empleado->setDireccion(direccion);
    empleado->setTelefono(telefono);
    empleado->setEmail(email);
    empleado->setSalario(salario);
    empleado->setHorario(horario);

    cout << "Empleado actualizado exitosamente.\n";
}

void EmpleadoView::eliminarEmpleado() {
    int id;
    cout << "Ingrese el ID del empleado a eliminar: ";
    cin >> id;

    if (empleadoCtrl.eliminar(id)) {
        cout << "Empleado eliminado exitosamente.\n";
    } else {
        cout << "Error: No existe un empleado con el ID " << id << ".\n";
    }
}
