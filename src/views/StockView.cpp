#include "StockView.h"
#include <iostream>
#include <limits>
#include <memory>
#include <algorithm>

using namespace std;

StockView::StockView(StockController& stockCtrl, ProductoController& productoCtrl)
    : stockCtrl(stockCtrl), productoCtrl(productoCtrl) {}

void StockView::mostrarMenu() {
    int opcion = 0;
    do {
        std::cout << "\n--- Gestionar Stock ---\n";
        std::cout << "1. Agregar Stock\n";
        std::cout << "2. Listar Stock\n";
        std::cout << "3. Actualizar Stock\n";
        std::cout << "4. Eliminar Stock\n";
        std::cout << "5. Mostrar productos con existencia bajo stock mínimo\n";
        std::cout << "6. Volver al Menú Principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor, ingrese un número.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                agregarStock();
                break;
            case 2:
                listarStocks();
                break;
            case 3:
                actualizarStock();
                break;
            case 4:
                eliminarStock();
                break;
            case 5:
                listarProductosBajoStockMinimo();
                break;
            case 6:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida.\n";
                break;
        }
    } while (opcion != 6);
}

void StockView::agregarStock() {
    int idStock, idProducto, existencias, stockMinimo;

    // Generar el siguiente ID de Stock
    auto stocks = stockCtrl.listarStocks();
    if (stocks.empty()) {
        idStock = 1;
    } else {
        idStock = max_element(stocks.begin(), stocks.end(),
                              [](const shared_ptr<Stock>& a, const shared_ptr<Stock>& b) {
                                  return a->getIdStock() < b->getIdStock();
                              })->get()->getIdStock() + 1;
    }

    cout << "Ingrese el ID del Producto: ";
    cin >> idProducto;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ID de producto inválido.\n";
        return;
    }

    // Verificar que el producto existe
    auto producto = productoCtrl.obtenerProductoPorId(idProducto);
    if (producto == nullptr) {
        cout << "Error: No existe un producto con el ID " << idProducto << ".\n";
        return;
    }

    cout << "Ingrese la cantidad de existencias: ";
    cin >> existencias;

    if (cin.fail() || existencias < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Cantidad de existencias inválida.\n";
        return;
    }

    cout << "Ingrese el stock mínimo permitido: ";
    cin >> stockMinimo;

    if (cin.fail() || stockMinimo < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Stock mínimo inválido.\n";
        return;
    }

    cin.ignore(); // Limpiar el buffer

    // Crear un nuevo registro de stock
    shared_ptr<Stock> nuevoStock = make_shared<Stock>(
        idStock, idProducto, existencias, stockMinimo
    );

    if (stockCtrl.agregarStock(nuevoStock)) {
        cout << "Stock agregado exitosamente con ID " << idStock << ".\n";
    } else {
        cout << "Error: No se pudo agregar el stock. Puede que ya exista un registro para este producto.\n";
    }
}

void StockView::listarStocks() {
    vector<shared_ptr<Stock>> stocks = stockCtrl.listarStocks();
    if (stocks.empty()) {
        cout << "No hay registros de stock.\n";
    } else {
        cout << "\nLista de Stocks:\n";
        cout << "ID Stock\tID Producto\tDescripción\tExistencias\tStock Mínimo\n";
        for (const auto& s : stocks) {
            auto producto = productoCtrl.obtenerProductoPorId(s->getIdProducto());
            string descripcion = (producto != nullptr) ? producto->getDescripcionProducto() : "Desconocida";
            cout << s->getIdStock() << "\t\t" 
                 << s->getIdProducto() << "\t\t" 
                 << descripcion << "\t\t" 
                 << s->getExistencias() << "\t\t" 
                 << s->getStockMinimo() << "\n";
        }
    }
}

void StockView::actualizarStock() {
    int idProducto, nuevaExistencias, nuevoStockMinimo;

    cout << "Ingrese el ID del Producto a actualizar: ";
    cin >> idProducto;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ID de producto inválido.\n";
        return;
    }

    auto stock = stockCtrl.obtenerStockPorIdProducto(idProducto);
    if (stock == nullptr) {
        cout << "Error: No existe un registro de stock para el producto con ID " << idProducto << ".\n";
        return;
    }

    cout << "Ingrese la nueva cantidad de existencias (actual: " << stock->getExistencias() << "): ";
    cin >> nuevaExistencias;

    if (cin.fail() || nuevaExistencias < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Cantidad de existencias inválida.\n";
        return;
    }

    cout << "Ingrese el nuevo stock mínimo permitido (actual: " << stock->getStockMinimo() << "): ";
    cin >> nuevoStockMinimo;

    if (cin.fail() || nuevoStockMinimo < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Stock mínimo inválido.\n";
        return;
    }

    // Actualizar el registro de stock
    if (stockCtrl.aumentarStock(idProducto, nuevaExistencias - stock->getExistencias()) ||
        stockCtrl.reducirStock(idProducto, stock->getExistencias() - nuevaExistencias)) {
        stock->setStockMinimo(nuevoStockMinimo);
        cout << "Stock actualizado exitosamente.\n";
    } else {
        cout << "Error: No se pudo actualizar el stock.\n";
    }
}

void StockView::eliminarStock() {
    int idProducto;

    cout << "Ingrese el ID del Producto a eliminar del stock: ";
    cin >> idProducto;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ID de producto inválido.\n";
        return;
    }

}

void StockView::listarProductosBajoStockMinimo() {
    std::vector<Stock> productosBajoMinimo = stockCtrl.listarBajoStockMinimo();

    if (productosBajoMinimo.empty()) {
        std::cout << "No hay productos con existencias bajo el stock mínimo.\n";
        return;
    }

    std::cout << "\n--- Productos con existencia menor al stock mínimo ---\n";
    std::cout << "ID Producto\tDescripción\tExistencias\tStock Mínimo\n";

    for (const auto& st : productosBajoMinimo) {
        int idProd = st.getIdProducto();
        Producto* prod = productoCtrl.obtenerProductoPorId(idProd);

        std::string descripcion = (prod) ? prod->getDescripcionProducto() : "Producto no encontrado";

        std::cout << idProd << "\t\t" 
                  << descripcion << "\t\t"
                  << st.getExistencias() << "\t\t"
                  << st.getStockMinimo() << "\n";
    }
}