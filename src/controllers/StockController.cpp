#include "StockController.h"

bool StockController::agregarStock(const std::shared_ptr<Stock>& stock) {
    // Verificar si el IDProducto ya existe
    for (const auto& s : stocks) {
        if (s->getIdProducto() == stock->getIdProducto()) {
            return false; // IDProducto duplicado
        }
    }
    stocks.push_back(stock);
    return true;
}

std::shared_ptr<Stock> StockController::obtenerStockPorIdProducto(int idProducto) const {
    for (const auto& s : stocks) {
        if (s->getIdProducto() == idProducto) {
            return s;
        }
    }
    return nullptr; // No encontrado
}

bool StockController::aumentarStock(int idProducto, int cantidad) {
    auto stock = obtenerStockPorIdProducto(idProducto);
    if (stock) {
        stock->setExistencias(stock->getExistencias() + cantidad);
        return true;
    }
    return false;
}

bool StockController::reducirStock(int idProducto, int cantidad) {
    auto stock = obtenerStockPorIdProducto(idProducto);
    if (stock && stock->getExistencias() >= cantidad) {
        stock->setExistencias(stock->getExistencias() - cantidad);
        return true;
    }
    return false;
}



std::vector<std::shared_ptr<Stock>> StockController::listarStocks() const {
    return stocks;


}


std::vector<Stock> StockController::listarBajoStockMinimo() const {
    std::vector<Stock> bajoStock;
    for (const auto& s : stocks) {
        if (s->getExistencias() < s->getStockMinimo()) {
            bajoStock.push_back(*s);
        }
    }
    return bajoStock;
}
