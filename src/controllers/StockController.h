
#ifndef STOCKCONTROLLER_H
#define STOCKCONTROLLER_H

#include <vector>
#include <memory>
#include "Stock.h"

class StockController {
private:
    std::vector<std::shared_ptr<Stock>> stocks;

public:
    // Agregar un nuevo registro de stock
    bool agregarStock(const std::shared_ptr<Stock>& stock);

    // Obtener un registro de stock por ID del producto
    std::shared_ptr<Stock> obtenerStockPorIdProducto(int idProducto) const;

    // Aumentar existencias de un producto en el inventario
    bool aumentarStock(int idProducto, int cantidad);

    // Reducir existencias de un producto en el inventario
    bool reducirStock(int idProducto, int cantidad);

    // Listar todos los registros de stock
    std::vector<std::shared_ptr<Stock>> listarStocks() const;

    std::vector<Stock> listarBajoStockMinimo() const;

};

#endif // STOCKCONTROLLER_H
