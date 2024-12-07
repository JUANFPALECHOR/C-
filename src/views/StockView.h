#ifndef STOCK_VIEW_H
#define STOCK_VIEW_H

#include "../controllers/StockController.h"
#include "../controllers/ProductoController.h"
#include <iostream>
#include <limits>

class StockView {
public:
    StockView(StockController& stockCtrl, ProductoController& productoCtrl);
    void mostrarMenu();

private:
    StockController& stockCtrl;
    ProductoController& productoCtrl;

    void agregarStock();
    void listarStocks();
    void actualizarStock();
    void eliminarStock();
    void listarProductosBajoStockMinimo();
};

#endif 
