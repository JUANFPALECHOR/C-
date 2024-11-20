// StockController.cpp
#include "StockController.h"

bool StockController::agregarStock(const Stock& stock) {
    // Verificar si el IDProducto ya existe
    for (const auto& s : stocks) {
        if (s.getIdProducto() == stock.getIdProducto()) {
            return false; // IDProducto duplicado
        }
    }
    stocks.push_back(stock);
    return true;
}

Stock* StockController::obtenerStockPorIdProducto(int idProducto) {
    for (auto& s : stocks) {
        if (s.getIdProducto() == idProducto) {
            return &s;
        }
    }
    return nullptr;
}

bool StockController::aumentarStock(int idProducto, int cantidad) {
    Stock* stock = obtenerStockPorIdProducto(idProducto);
    if (stock) {
        stock->setExistencias(stock->getExistencias() + cantidad);
        return true;
    }
    return false;
}

bool StockController::reducirStock(int idProducto, int cantidad) {
    Stock* stock = obtenerStockPorIdProducto(idProducto);
    if (stock && stock->getExistencias() >= cantidad) {
        stock->setExistencias(stock->getExistencias() - cantidad);
        return true;
    }
    return false;
}

std::vector<Stock> StockController::listarStocks() const {
    return stocks;
}
