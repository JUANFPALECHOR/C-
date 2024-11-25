#include "MarcaView.h"
#include <iostream>
#include <limits>

using namespace std;

MarcaView::MarcaView(MarcaController& marcaCtrl) : marcaCtrl(marcaCtrl) {}

void MarcaView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Marcas ---\n";
        cout << "1. Agregar Marca\n";
        cout << "2. Listar Marcas\n";
        cout << "3. Actualizar Marca\n";
        cout << "4. Eliminar Marca\n";
        cout << "5. Volver al Menú Principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch(opcion) {
            case 1:
                agregarMarca();
                break;
            case 2:
                listarMarcas();
                break;
            case 3:
                actualizarMarca();
                break;
            case 4:
                eliminarMarca();
                break;
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while(opcion != 5);
}

void MarcaView::agregarMarca() {
    int nuevoID;
    string nombreMarca;

    cout << "Ingrese el ID de la nueva marca: ";
    cin >> nuevoID;

    // Verificar si el ID ya existe
    if (marcaCtrl.obtenerMarcaPorId(nuevoID) != nullptr) {
        cout << "Error: Ya existe una marca con el ID " << nuevoID << ".\n";
        return;
    }

    cout << "Ingrese el nombre de la marca: ";
    cin.ignore();
    getline(cin, nombreMarca);

    // Validaciones
    if (nombreMarca.empty()) {
        cout << "Error: El nombre de la marca no puede estar vacío.\n";
        return;
    }

    Marca nuevaMarca(nuevoID, nombreMarca);

    if (marcaCtrl.agregarMarca(nuevaMarca)) {
        cout << "Marca agregada exitosamente con ID " << nuevoID << ".\n";
    } else {
        cout << "Error: No se pudo agregar la marca.\n";
    }
}

void MarcaView::listarMarcas() {
    vector<Marca> marcas = marcaCtrl.listarMarcas();
    if(marcas.empty()) {
        cout << "No hay marcas registradas.\n";
    } else {
        cout << "\nLista de Marcas:\n";
        cout << "ID\tNombre\n";
        for(const auto& m : marcas) {
            cout << m.getIdMarca() << "\t" 
                 << m.getNombreMarca() << "\n";
        }
    }
}

void MarcaView::actualizarMarca() {
    int id;
    cout << "Ingrese el ID de la marca a actualizar: ";
    cin >> id;

    Marca* marca = marcaCtrl.obtenerMarcaPorId(id);
    if(!marca) {
        cout << "Error: Marca con ID " << id << " no encontrada.\n";
        return;
    }

    string nuevoNombre;

    cout << "Ingrese el nuevo nombre de la marca (actual: " 
         << marca->getNombreMarca() << "): ";
    cin.ignore();
    getline(cin, nuevoNombre);

    if(!Validator::noVacio(nuevoNombre)) {
        cout << "Error: El nombre de la marca no puede estar vacío.\n";
        return;
    }

    marca->setNombreMarca(nuevoNombre);

    cout << "Marca actualizada exitosamente.\n";
}

void MarcaView::eliminarMarca() {
    int id;
    cout << "Ingrese el ID de la marca a eliminar: ";
    cin >> id;

    if(marcaCtrl.eliminarMarca(id)) {
        cout << "Marca eliminada exitosamente.\n";
    } else {
        cout << "Error: Marca con ID " << id << " no encontrada.\n";
    }
}
