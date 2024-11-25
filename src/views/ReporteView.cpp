#include "ReporteView.h"

ReporteView::ReporteView(ReporteController& reporteCtrl, MarcaController& marcaCtrl)
    : reporteController(reporteCtrl), marcaController(marcaCtrl) {}

// Método para imprimir productos por marca
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

    // Asumiendo que obtenerMarcaPorId retorna una copia de Marca
    Marca marcaSeleccionada = marcaController.obtenerMarcaPorId(idMarca);
    if(marcaSeleccionada.getIdMarca() == 0) { // Asumiendo que ID 0 no es válido
        std::cout << "Marca con ID " << idMarca << " no encontrada.\n";
        return;
    }

    std::vector<Producto> productos = reporteController.mostrarProductosPorMarca(idMarca);

    if(productos.empty()) {
        std::cout << "No hay productos asociados a la marca \"" << marcaSeleccionada.getNombreMarca() << "\".\n";
        return;
    }

    std::cout << "\n--- Productos de la Marca \"" << marcaSeleccionada.getNombreMarca() << "\" ---\n";
    for(const auto& producto : productos) {
        std::cout << "ID: " << producto.getIdProducto()
                  << " | Precio: $" << producto.getPrecio() << "\n";
    }
}

