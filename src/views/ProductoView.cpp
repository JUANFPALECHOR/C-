#include "ProductoView.h"
#include <iostream>
#include <limits>

using namespace std;

ProductoView::ProductoView(ProductoController& productoCtrl, MarcaController& marcaCtrl)
    : productoCtrl(productoCtrl), marcaCtrl(marcaCtrl) {}

void ProductoView::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n--- Gestionar Productos ---\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Listar Productos\n";
        cout << "3. Actualizar Producto\n";
        cout << "4. Eliminar Producto\n";
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
                agregarProducto();
                break;
            case 2:
                listarProductos();
                break;
            case 3:
                actualizarProducto();
                break;
            case 4:
                eliminarProducto();
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

void ProductoView::agregarProducto() {
    string descripcion;
    int idMarca;
    double precio;

    // Obtener el siguiente ID disponible para el producto
    int nuevoID = productoCtrl.listarProductos().size() + 1;

    cout << "Ingrese la descripción del producto: ";
    cin.ignore();
    getline(cin, descripcion);

    if(descripcion.empty()) {
        cout << "Error: La descripción del producto no puede estar vacía.\n";
        return;
    }

    cout << "Ingrese el ID de la marca asociada: ";
    cin >> idMarca;

    // Verificar que la marca existe
    if(marcaCtrl.obtenerMarcaPorId(idMarca) == nullptr) {
        cout << "Error: La marca con ID " << idMarca << " no existe.\n";
        return;
    }

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    if(cin.fail() || precio < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Precio inválido.\n";
        return;
    }

    Producto nuevoProducto(nuevoID, descripcion, idMarca, precio);

    if(productoCtrl.agregarProducto(nuevoProducto)) {
        cout << "Producto agregado exitosamente con ID " << nuevoID << ".\n";
    } else {
        cout << "Error: No se pudo agregar el producto.\n";
    }
}

void ProductoView::listarProductos() {
    vector<Producto> productos = productoCtrl.listarProductos();
    if(productos.empty()) {
        cout << "No hay productos registrados.\n";
    } else {
        cout << "\nLista de Productos:\n";
        cout << "ID\tDescripción\tMarca\tPrecio\n";
        for(const auto& p : productos) {
            Marca* marca = marcaCtrl.obtenerMarcaPorId(p.getIdMarca());
            string nombreMarca = (marca != nullptr) ? marca->getNombreMarca() : "Desconocida";
            cout << p.getIdProducto() << "\t"
                 << p.getDescripcionProducto() << "\t"
                 << nombreMarca << "\t"
                 << p.getPrecio() << "\n";
        }
    }
}

void ProductoView::actualizarProducto() {
    int idProducto;
    cout << "Ingrese el ID del producto a actualizar: ";
    cin >> idProducto;

    Producto* producto = productoCtrl.obtenerProductoPorId(idProducto);
    if(producto == nullptr) {
        cout << "Error: Producto con ID " << idProducto << " no encontrado.\n";
        return;
    }

    string nuevaDescripcion;
    int nuevoIdMarca;
    double nuevoPrecio;

    cout << "Ingrese la nueva descripción del producto (actual: " << producto->getDescripcionProducto() << "): ";
    cin.ignore();
    getline(cin, nuevaDescripcion);

    if(nuevaDescripcion.empty()) {
        cout << "Error: La descripción del producto no puede estar vacía.\n";
        return;
    }

    cout << "Ingrese el nuevo ID de la marca asociada (actual: " << producto->getIdMarca() << "): ";
    cin >> nuevoIdMarca;

    if(marcaCtrl.obtenerMarcaPorId(nuevoIdMarca) == nullptr) {
        cout << "Error: La marca con ID " << nuevoIdMarca << " no existe.\n";
        return;
    }

    cout << "Ingrese el nuevo precio del producto (actual: " << producto->getPrecio() << "): ";
    cin >> nuevoPrecio;

    if(cin.fail() || nuevoPrecio < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Precio inválido.\n";
        return;
    }

    // Actualizar el producto
    producto->setDescripcionProducto(nuevaDescripcion);
    producto->setIdMarca(nuevoIdMarca);
    producto->setPrecio(nuevoPrecio);

    cout << "Producto actualizado exitosamente.\n";
}

void ProductoView::eliminarProducto() {
    int idProducto;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> idProducto;

    if(productoCtrl.eliminarProducto(idProducto)) {
        cout << "Producto eliminado exitosamente.\n";
    } else {
        cout << "Error: Producto con ID " << idProducto << " no encontrado.\n";
    }
}
