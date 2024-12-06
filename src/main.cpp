// main.cpp

#include <iostream>
#include <limits>
#include "controllers/ProductoController.h"
#include "controllers/MarcaController.h"
#include "controllers/EmpleadoController.h"
#include "controllers/ClienteController.h"
#include "controllers/ProveedorController.h"
#include "controllers/StockController.h"
#include "controllers/FacturaController.h"
#include "controllers/ReporteController.h"
#include "utils/IDGenerator.h"
#include "models/Producto.h"
#include "models/Marca.h"
#include "models/Empleado.h"
#include "models/Cliente.h"
#include "models/Proveedor.h"
#include "utils/Validator.h"
#include "views/MarcaView.h"
#include "views/ProductoView.h"
#include "views/EmpleadoView.h"
#include "views/ClienteView.h"
#include "views/ProveedorView.h"
#include "views/StockView.h"
#include "views/FacturaView.h"
#include "views/ReporteView.h"


using namespace std;

// Funciones para manejar el menú
void mostrarMenu();
void manejarMenu(ProductoController& productoCtrl, MarcaController& marcaCtrl,
                EmpleadoController& empleadoCtrl, ClienteController& clienteCtrl,
                ProveedorController& proveedorCtrl,StockController & stockCtrl,
                FacturaController&facturaCtrl, ReporteController& reporteCtrl);

int main() {
    // Crear instancias de los controladores
    ProductoController productoCtrl;
    MarcaController marcaCtrl;
    EmpleadoController empleadoCtrl;
    ClienteController clienteCtrl;
    ProveedorController proveedorCtrl;
    StockController stockCtrl;
    FacturaController facturaCtrl(stockCtrl);
    ReporteController reporteCtrl(facturaCtrl, stockCtrl, clienteCtrl, empleadoCtrl, productoCtrl, marcaCtrl);

    //MarcaView marcaView(marcaCtrl);
    //marcaView.mostrarMenu();

    // Inicializar el generador de IDs (Singleton)
    IDGenerator* idGen = IDGenerator::getInstance();

    // Llamar al manejador del menú
    manejarMenu(productoCtrl, marcaCtrl, empleadoCtrl, clienteCtrl, proveedorCtrl,stockCtrl,facturaCtrl,reporteCtrl);

    return 0;
}

void mostrarMenu() {
    cout << "\n=== Tienda de Comercio Electrónico ===\n";
    cout << "1. Gestionar Productos\n";
    cout << "2. Gestionar Marcas\n";
    cout << "3. Gestionar Empleados\n";
    cout << "4. Gestionar Clientes\n";
    cout << "5. Gestionar Proveedores\n";
    cout << "6. Gestionar Stock\n";
    cout << "7. Procesar Facturas\n";  
    cout << "8. Reportes\n";  
    cout << "10. Salir\n";
    cout << "Seleccione una opción: ";
}

void manejarMenu(ProductoController& productoCtrl, MarcaController& marcaCtrl,
                 EmpleadoController& empleadoCtrl, ClienteController& clienteCtrl,
                 ProveedorController& proveedorCtrl, StockController& stockCtrl,
                 FacturaController& facturaCtrl, ReporteController& reporteCtrl) {
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

                ProductoView productoView(productoCtrl, marcaCtrl);
                productoView.mostrarMenu();
                break;
            }
            case 2: {
                MarcaView marcaView(marcaCtrl);
                marcaView.mostrarMenu();
                break;
            }
            case 3: {
                EmpleadoView empleadoView(empleadoCtrl);
                empleadoView.mostrarMenu();
                break;
            }
            case 4: {
                ClienteView clienteView(clienteCtrl);
                clienteView.mostrarMenu();
                break;
            }
            case 5: {
                ProveedorView proveedorView(proveedorCtrl);
                proveedorView.mostrarMenu();
                break;
            }
            case 6: {
                StockView stockView(stockCtrl, productoCtrl);
                stockView.mostrarMenu();
                break;
            }
            case 7: {
                FacturaView facturaView(facturaCtrl, empleadoCtrl, clienteCtrl, proveedorCtrl, productoCtrl, marcaCtrl);
                facturaView.mostrarMenu();
                break;
                
            }
            case 8: {
                ReporteView reporteView(reporteCtrl, marcaCtrl, productoCtrl);
                reporteView.mostrarMenuReportes();
                break;
            }
            case 9: {
                
            }

            case 10:
                cout << "Saliendo de la aplicación. ¡Hasta luego!\n";
                return;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
        }
    }
}
