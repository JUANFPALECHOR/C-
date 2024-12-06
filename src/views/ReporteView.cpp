#include "ReporteView.h"

ReporteView::ReporteView(ReporteController& reporteCtrl, MarcaController& marcaCtrl, ProductoController& productoCtrl)
    : reporteController(reporteCtrl), marcaController(marcaCtrl), productoController(productoCtrl) {}

void ReporteView::mostrarMenuReportes() {
    int opcion = 0;
    do {
        std::cout << "\n--- Menú de Reportes ---\n";
        std::cout << "1. Imprimir productos por marca\n";
        std::cout << "2. Volver al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch(opcion) {
            case 1:
                imprimirProductosPorMarca();
                break;
            case 2:
                std::cout << "Volviendo al menú principal...\n";
                break;
            default:
                std::cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while(opcion != 2);
}

void ReporteView::imprimirProductosPorMarca() {
    std::vector<Marca> marcas = marcaController.listarMarcas();

    if(marcas.empty()) {
        std::cout << "No hay marcas disponibles.\n";
        return;
    }

    std::cout << "\n--- Lista de Marcas ---\n";
    for(const auto& marca : marcas) {
        std::cout << "ID: " << marca.getIdMarca() << " | Nombre: " << marca.getNombreMarca() << "\n";
    }

    int idMarca;
    std::cout << "Ingrese el ID de la marca para ver sus productos: ";
    std::cin >> idMarca;

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Debe ingresar un número.\n";
        return;
    }

    // Obtener el puntero a la marca
    Marca* marcaSeleccionada = marcaController.obtenerMarcaPorId(idMarca);
    if (marcaSeleccionada == nullptr) {
        std::cout << "Marca con ID " << idMarca << " no encontrada.\n";
        return;
    }

    // Ahora utilizamos productoController para obtener los productos
    std::vector<Producto> productos = productoController.obtenerProductosPorMarca(idMarca);

    if(productos.empty()) {
        std::cout << "No hay productos asociados a la marca \"" << marcaSeleccionada->getNombreMarca() << "\".\n";
        return;
    }

    std::cout << "\n--- Productos de la Marca \"" << marcaSeleccionada->getNombreMarca() << "\" ---\n";
    std::cout << "ID\tDescripción\tPrecio\n";
    for(const auto& producto : productos) {
        std::cout << producto.getIdProducto() << "\t"
                  << producto.getDescripcionProducto() << "\t"
                  << producto.getPrecio() << "\n";
    }
}
