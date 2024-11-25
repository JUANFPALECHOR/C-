#include "ClienteView.h"
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

ClienteView::ClienteView(ClienteController& clienteCtrl)
    : clienteCtrl(clienteCtrl) {}

void ClienteView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Clientes ---\n";
        cout << "1. Agregar Cliente\n";
        cout << "2. Listar Clientes\n";
        cout << "3. Actualizar Cliente\n";
        cout << "4. Eliminar Cliente\n";
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
                agregarCliente();
                break;
            case 2:
                listarClientes();
                break;
            case 3:
                actualizarCliente();
                break;
            case 4:
                eliminarCliente();
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

void ClienteView::agregarCliente() {
    int id;
    string rut, nombre, direccion, telefono, email, profesion;
    int tipoClienteInt;
    TipoCliente tipoCliente;

    cout << "Ingrese el ID del cliente: ";
    cin >> id;

    if (clienteCtrl.obtenerPorId(id) != nullptr) {
        cout << "Error: Ya existe un cliente con el ID " << id << ".\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el RUT del cliente: ";
    getline(cin, rut);

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombre);

    cout << "Ingrese la dirección del cliente: ";
    getline(cin, direccion);

    cout << "Ingrese el teléfono del cliente: ";
    getline(cin, telefono);

    cout << "Ingrese el email del cliente: ";
    getline(cin, email);

    cout << "Ingrese la profesión del cliente: ";
    getline(cin, profesion);

    cout << "Seleccione el tipo de cliente:\n";
    cout << "1. Pensionado\n";
    cout << "2. Empleado Público\n";
    cout << "3. Empresario\n";
    cout << "4. Militar\n";
    cout << "Seleccione una opción: ";
    cin >> tipoClienteInt;

    if (cin.fail() || tipoClienteInt < 1 || tipoClienteInt > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Tipo de cliente inválido.\n";
        return;
    }

    tipoCliente = static_cast<TipoCliente>(tipoClienteInt - 1);

    // Crear un nuevo cliente
    shared_ptr<Cliente> nuevoCliente = make_shared<Cliente>(
        id, rut, nombre, direccion, telefono, email, profesion, tipoCliente);

    if (clienteCtrl.agregar(nuevoCliente)) {
        cout << "Cliente agregado exitosamente.\n";
    } else {
        cout << "Error: No se pudo agregar el cliente.\n";
    }
}

void ClienteView::listarClientes() {
    vector<shared_ptr<Cliente>> clientes = clienteCtrl.listar();
    if (clientes.empty()) {
        cout << "No hay clientes registrados.\n";
    } else {
        cout << "\nLista de Clientes:\n";
        cout << "ID\tNombre\tRUT\tTipo\n";
        for (const auto& c : clientes) {
            cout << c->getId() << "\t" << c->getNombre() << "\t"
                 << c->getRut() << "\t" << c->tipoClienteToString() << "\n";
        }
    }
}

void ClienteView::actualizarCliente() {
    int id;
    cout << "Ingrese el ID del cliente a actualizar: ";
    cin >> id;

    shared_ptr<Cliente> cliente = clienteCtrl.obtenerPorId(id);
    if (cliente == nullptr) {
        cout << "Error: No existe un cliente con el ID " << id << ".\n";
        return;
    }

    string rut, nombre, direccion, telefono, email, profesion;
    int tipoClienteInt;
    TipoCliente tipoCliente;

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el nuevo RUT del cliente (actual: " << cliente->getRut() << "): ";
    getline(cin, rut);

    cout << "Ingrese el nuevo nombre del cliente (actual: " << cliente->getNombre() << "): ";
    getline(cin, nombre);

    cout << "Ingrese la nueva dirección del cliente (actual: " << cliente->getDireccion() << "): ";
    getline(cin, direccion);

    cout << "Ingrese el nuevo teléfono del cliente (actual: " << cliente->getTelefono() << "): ";
    getline(cin, telefono);

    cout << "Ingrese el nuevo email del cliente (actual: " << cliente->getEmail() << "): ";
    getline(cin, email);

    cout << "Ingrese la nueva profesión del cliente (actual: " << cliente->getProfesion() << "): ";
    getline(cin, profesion);

    cout << "Seleccione el nuevo tipo de cliente:\n";
    cout << "1. Pensionado\n";
    cout << "2. Empleado Público\n";
    cout << "3. Empresario\n";
    cout << "4. Militar\n";
    cout << "Seleccione una opción: ";
    cin >> tipoClienteInt;

    if (cin.fail() || tipoClienteInt < 1 || tipoClienteInt > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Tipo de cliente inválido.\n";
        return;
    }

    tipoCliente = static_cast<TipoCliente>(tipoClienteInt - 1);

    // Actualizar los datos del cliente
    cliente->setRut(rut);
    cliente->setNombre(nombre);
    cliente->setDireccion(direccion);
    cliente->setTelefono(telefono);
    cliente->setEmail(email);
    cliente->setProfesion(profesion);
    cliente->setTipoCliente(tipoCliente);

    cout << "Cliente actualizado exitosamente.\n";
}

void ClienteView::eliminarCliente() {
    int id;
    cout << "Ingrese el ID del cliente a eliminar: ";
    cin >> id;

    if (clienteCtrl.eliminar(id)) {
        cout << "Cliente eliminado exitosamente.\n";
    } else {
        cout << "Error: No existe un cliente con el ID " << id << ".\n";
    }
}
