#include "ProveedorView.h"
#include <iostream>
#include <limits>
#include <memory>

using namespace std;

ProveedorView::ProveedorView(ProveedorController& proveedorCtrl)
    : proveedorCtrl(proveedorCtrl) {}

void ProveedorView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Proveedores ---\n";
        cout << "1. Agregar Proveedor\n";
        cout << "2. Listar Proveedores\n";
        cout << "3. Actualizar Proveedor\n";
        cout << "4. Eliminar Proveedor\n";
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
                agregarProveedor();
                break;
            case 2:
                listarProveedores();
                break;
            case 3:
                actualizarProveedor();
                break;
            case 4:
                eliminarProveedor();
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

void ProveedorView::agregarProveedor() {
    int id;
    string rut, nombre, direccion, telefono, email, banco, nroCuenta;
    int tipoCuentaInt;
    TipoCuenta tipoCuenta;

    cout << "Ingrese el ID del proveedor: ";
    cin >> id;

    if (proveedorCtrl.obtenerPorId(id) != nullptr) {
        cout << "Error: Ya existe un proveedor con el ID " << id << ".\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el RUT del proveedor: ";
    getline(cin, rut);

    cout << "Ingrese el nombre del proveedor: ";
    getline(cin, nombre);

    cout << "Ingrese la dirección del proveedor: ";
    getline(cin, direccion);

    cout << "Ingrese el teléfono del proveedor: ";
    getline(cin, telefono);

    cout << "Ingrese el email del proveedor: ";
    getline(cin, email);

    cout << "Ingrese el banco del proveedor: ";
    getline(cin, banco);

    cout << "Ingrese el número de cuenta del proveedor: ";
    getline(cin, nroCuenta);

    cout << "Seleccione el tipo de cuenta:\n";
    cout << "1. Ahorros\n";
    cout << "2. Corriente\n";
    cout << "Seleccione una opción: ";
    cin >> tipoCuentaInt;

    if (cin.fail() || tipoCuentaInt < 1 || tipoCuentaInt > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Tipo de cuenta inválido.\n";
        return;
    }

    tipoCuenta = static_cast<TipoCuenta>(tipoCuentaInt - 1);

    // Crear un nuevo proveedor
    shared_ptr<Proveedor> nuevoProveedor = make_shared<Proveedor>(
        id, rut, nombre, direccion, telefono, email, banco, nroCuenta, tipoCuenta);

    if (proveedorCtrl.agregar(nuevoProveedor)) {
        cout << "Proveedor agregado exitosamente.\n";
    } else {
        cout << "Error: No se pudo agregar el proveedor.\n";
    }
}

void ProveedorView::listarProveedores() {
    vector<shared_ptr<Proveedor>> proveedores = proveedorCtrl.listar();
    if (proveedores.empty()) {
        cout << "No hay proveedores registrados.\n";
    } else {
        cout << "\nLista de Proveedores:\n";
        cout << "ID\tNombre\tRUT\tBanco\tTipo Cuenta\n";
        for (const auto& p : proveedores) {
            cout << p->getId() << "\t" << p->getNombre() << "\t"
                 << p->getRut() << "\t" << p->getBanco() << "\t"
                 << p->tipoCuentaToString() << "\n";
        }
    }
}

void ProveedorView::actualizarProveedor() {
    int id;
    cout << "Ingrese el ID del proveedor a actualizar: ";
    cin >> id;

    shared_ptr<Proveedor> proveedor = proveedorCtrl.obtenerPorId(id);
    if (proveedor == nullptr) {
        cout << "Error: No existe un proveedor con el ID " << id << ".\n";
        return;
    }

    string rut, nombre, direccion, telefono, email, banco, nroCuenta;
    int tipoCuentaInt;
    TipoCuenta tipoCuenta;

    cin.ignore(); // Limpiar el buffer

    cout << "Ingrese el nuevo RUT del proveedor (actual: " << proveedor->getRut() << "): ";
    getline(cin, rut);

    cout << "Ingrese el nuevo nombre del proveedor (actual: " << proveedor->getNombre() << "): ";
    getline(cin, nombre);

    cout << "Ingrese la nueva dirección del proveedor (actual: " << proveedor->getDireccion() << "): ";
    getline(cin, direccion);

    cout << "Ingrese el nuevo teléfono del proveedor (actual: " << proveedor->getTelefono() << "): ";
    getline(cin, telefono);

    cout << "Ingrese el nuevo email del proveedor (actual: " << proveedor->getEmail() << "): ";
    getline(cin, email);

    cout << "Ingrese el nuevo banco del proveedor (actual: " << proveedor->getBanco() << "): ";
    getline(cin, banco);

    cout << "Ingrese el nuevo número de cuenta del proveedor (actual: " << proveedor->getNroCuenta() << "): ";
    getline(cin, nroCuenta);

    cout << "Seleccione el nuevo tipo de cuenta:\n";
    cout << "1. Ahorros\n";
    cout << "2. Corriente\n";
    cout << "Seleccione una opción: ";
    cin >> tipoCuentaInt;

    if (cin.fail() || tipoCuentaInt < 1 || tipoCuentaInt > 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Tipo de cuenta inválido.\n";
        return;
    }

    tipoCuenta = static_cast<TipoCuenta>(tipoCuentaInt - 1);

    // Actualizar los datos del proveedor
    proveedor->setRut(rut);
    proveedor->setNombre(nombre);
    proveedor->setDireccion(direccion);
    proveedor->setTelefono(telefono);
    proveedor->setEmail(email);
    proveedor->setBanco(banco);
    proveedor->setNroCuenta(nroCuenta);
    proveedor->setTipoCuenta(tipoCuenta);

    cout << "Proveedor actualizado exitosamente.\n";
}

void ProveedorView::eliminarProveedor() {
    int id;
    cout << "Ingrese el ID del proveedor a eliminar: ";
    cin >> id;

    if (proveedorCtrl.eliminar(id)) {
        cout << "Proveedor eliminado exitosamente.\n";
    } else {
        cout << "Error: No existe un proveedor con el ID " << id << ".\n";
    }
}
