// main.cpp

#include <iostream>
#include <limits>
#include "controllers/ProductoController.h"
#include "controllers/MarcaController.h"
#include "utils/IDGenerator.h"
#include "models/Producto.h"
#include "models/Marca.h"
#include "utils/Validator.h"

using namespace std;

// Funciones para manejar el menú
void mostrarMenu();
void manejarMenu(ProductoController& productoCtrl, MarcaController& marcaCtrl);

int main() {
    // Crear instancias de los controladores
    ProductoController productoCtrl;
    MarcaController marcaCtrl;

    // Inicializar el generador de IDs (Singleton)
    IDGenerator* idGen = IDGenerator::getInstance();

    // Llamar al manejador del menú
    manejarMenu(productoCtrl, marcaCtrl);

    return 0;
}

void mostrarMenu() {
    cout << "\n=== Tienda de Comercio Electrónico ===\n";
    cout << "1. Gestionar Productos\n";
    cout << "2. Gestionar Marcas\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

void manejarMenu(ProductoController& productoCtrl, MarcaController& marcaCtrl) {
    int opcion = 0;

    while (true) {
        mostrarMenu();
        cin >> opcion;

        // Validar entrada
        if(cin.fail()) {
            cin.clear(); // Limpiar el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar el resto de la línea
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch(opcion) {
            case 1: {
                // Submenú para Productos
                int subOpcion = 0;
                while (true) {
                    cout << "\n--- Gestionar Productos ---\n";
                    cout << "1. Agregar Producto\n";
                    cout << "2. Listar Productos\n";
                    cout << "3. Actualizar Producto\n";
                    cout << "4. Eliminar Producto\n";
                    cout << "5. Volver al Menú Principal\n";
                    cout << "Seleccione una opción: ";
                    cin >> subOpcion;

                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Entrada inválida. Por favor, ingrese un número.\n";
                        continue;
                    }

                    if(subOpcion == 5) break;

                    switch(subOpcion) {
                        case 1: {
                            // Agregar Producto
                            int idMarca;
                            string descripcion;
                            
                            cout << "Ingrese la descripción del producto: ";
                            cin.ignore(); // Limpiar el buffer
                            getline(cin, descripcion);

                            cout << "Ingrese el ID de la marca: ";
                            cin >> idMarca;

                            // Validaciones
                            if(!Validator::noVacio(descripcion)) {
                                cout << "Error: La descripción no puede estar vacía.\n";
                                break;
                            }
                            if(!Validator::esPositivo(idMarca)) {
                                cout << "Error: El ID de la marca debe ser positivo.\n";
                                break;
                            }

                            // Verificar si la marca existe
                            Marca* marca = marcaCtrl.obtenerMarcaPorId(idMarca);
                            if(!marca) {
                                cout << "Error: Marca con ID " << idMarca << " no encontrada.\n";
                                break;
                            }

                            // Generar ID único para el producto
                            int nuevoID = IDGenerator::getInstance()->generarID("Producto");

                            Producto nuevoProducto(nuevoID, descripcion, idMarca);

                            if(productoCtrl.agregarProducto(nuevoProducto)) {
                                cout << "Producto agregado exitosamente con ID " << nuevoID << ".\n";
                            } else {
                                cout << "Error: No se pudo agregar el producto.\n";
                            }

                            break;
                        }
                        case 2: {
                            // Listar Productos
                            vector<Producto> productos = productoCtrl.listarProductos();
                            if(productos.empty()) {
                                cout << "No hay productos registrados.\n";
                            } else {
                                cout << "\nLista de Productos:\n";
                                cout << "ID\tDescripción\tID Marca\n";
                                for(const auto& p : productos) {
                                    cout << p.getIdProducto() << "\t" 
                                         << p.getDescripcionProducto() << "\t" 
                                         << p.getIdMarca() << "\n";
                                }
                            }
                            break;
                        }
                        case 3: {
                            // Actualizar Producto
                            int id;
                            cout << "Ingrese el ID del producto a actualizar: ";
                            cin >> id;

                            Producto* producto = productoCtrl.obtenerProductoPorId(id);
                            if(!producto) {
                                cout << "Error: Producto con ID " << id << " no encontrado.\n";
                                break;
                            }

                            string nuevaDescripcion;
                            int nuevoIdMarca;

                            cout << "Ingrese la nueva descripción (actual: " 
                                 << producto->getDescripcionProducto() << "): ";
                            cin.ignore();
                            getline(cin, nuevaDescripcion);

                            cout << "Ingrese el nuevo ID de la marca (actual: " 
                                 << producto->getIdMarca() << "): ";
                            cin >> nuevoIdMarca;

                            // Validaciones
                            if(!Validator::noVacio(nuevaDescripcion)) {
                                cout << "Error: La descripción no puede estar vacía.\n";
                                break;
                            }
                            if(!Validator::esPositivo(nuevoIdMarca)) {
                                cout << "Error: El ID de la marca debe ser positivo.\n";
                                break;
                            }

                            // Verificar si la marca existe
                            Marca* marca = marcaCtrl.obtenerMarcaPorId(nuevoIdMarca);
                            if(!marca) {
                                cout << "Error: Marca con ID " << nuevoIdMarca << " no encontrada.\n";
                                break;
                            }

                            // Actualizar el producto
                            producto->setDescripcionProducto(nuevaDescripcion);
                            producto->setIdMarca(nuevoIdMarca);

                            cout << "Producto actualizado exitosamente.\n";

                            break;
                        }
                        case 4: {
                            // Eliminar Producto
                            int id;
                            cout << "Ingrese el ID del producto a eliminar: ";
                            cin >> id;

                            if(productoCtrl.eliminarProducto(id)) {
                                cout << "Producto eliminado exitosamente.\n";
                            } else {
                                cout << "Error: Producto con ID " << id << " no encontrado.\n";
                            }

                            break;
                        }
                        default:
                            cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                    }
                }
                break;
            }
            case 2: {
                // Submenú para Marcas
                int subOpcion = 0;
                while (true) {
                    cout << "\n--- Gestionar Marcas ---\n";
                    cout << "1. Agregar Marca\n";
                    cout << "2. Listar Marcas\n";
                    cout << "3. Actualizar Marca\n";
                    cout << "4. Eliminar Marca\n";
                    cout << "5. Volver al Menú Principal\n";
                    cout << "Seleccione una opción: ";
                    cin >> subOpcion;

                    if(cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Entrada inválida. Por favor, ingrese un número.\n";
                        continue;
                    }

                    if(subOpcion == 5) break;

                    switch(subOpcion) {
                        case 1: {
                            // Agregar Marca
                            string nombreMarca;
                            
                            cout << "Ingrese el nombre de la marca: ";
                            cin.ignore();
                            getline(cin, nombreMarca);

                            // Validaciones
                            if(!Validator::noVacio(nombreMarca)) {
                                cout << "Error: El nombre de la marca no puede estar vacío.\n";
                                break;
                            }

                            // Generar ID único para la marca
                            int nuevoID = IDGenerator::getInstance()->generarID("Marca");

                            Marca nuevaMarca(nuevoID, nombreMarca);

                            if(marcaCtrl.agregarMarca(nuevaMarca)) {
                                cout << "Marca agregada exitosamente con ID " << nuevoID << ".\n";
                            } else {
                                cout << "Error: No se pudo agregar la marca.\n";
                            }

                            break;
                        }
                        case 2: {
                            // Listar Marcas
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
                            break;
                        }
                        case 3: {
                            // Actualizar Marca
                            int id;
                            cout << "Ingrese el ID de la marca a actualizar: ";
                            cin >> id;

                            Marca* marca = marcaCtrl.obtenerMarcaPorId(id);
                            if(!marca) {
                                cout << "Error: Marca con ID " << id << " no encontrada.\n";
                                break;
                            }

                            string nuevoNombre;

                            cout << "Ingrese el nuevo nombre de la marca (actual: " 
                                 << marca->getNombreMarca() << "): ";
                            cin.ignore();
                            getline(cin, nuevoNombre);

                            // Validaciones
                            if(!Validator::noVacio(nuevoNombre)) {
                                cout << "Error: El nombre de la marca no puede estar vacío.\n";
                                break;
                            }

                            // Actualizar la marca
                            marca->setNombreMarca(nuevoNombre);

                            cout << "Marca actualizada exitosamente.\n";

                            break;
                        }
                        case 4: {
                            // Eliminar Marca
                            int id;
                            cout << "Ingrese el ID de la marca a eliminar: ";
                            cin >> id;

                            // Verificar si hay productos asociados a la marca
                            // (Suponiendo que tienes acceso al controlador de productos)
                            // En este ejemplo, omitimos esta verificación

                            if(marcaCtrl.eliminarMarca(id)) {
                                cout << "Marca eliminada exitosamente.\n";
                            } else {
                                cout << "Error: Marca con ID " << id << " no encontrada.\n";
                            }

                            break;
                        }
                        default:
                            cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                    }
                }
                break;
            }
            case 3:
                cout << "Saliendo de la aplicación. ¡Hasta luego!\n";
                return;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
        }
    }
}
