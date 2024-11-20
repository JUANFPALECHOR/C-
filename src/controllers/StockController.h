// StockController.h
#ifndef STOCKCONTROLLER_H
#define STOCKCONTROLLER_H

#include <vector>
#include "Stock.h"

class StockController {
private:
    std::vector<Stock> stocks;

public:
    // Agregar Stock
    bool agregarStock(const Stock& stock);

    // Obtener Stock por IDProducto
    Stock* obtenerStockPorIdProducto(int idProducto);

    // Actualizar existencias
    bool aumentarStock(int idProducto, int cantidad);
    bool reducirStock(int idProducto, int cantidad);

    // Listar todos los Stocks
    std::vector<Stock> listarStocks() const;
};

#endif // STOCKCONTROLLER_H
