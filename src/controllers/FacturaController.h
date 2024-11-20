// FacturaController.h
#ifndef FACTURACONTROLLER_H
#define FACTURACONTROLLER_H

#include <vector>
#include "Factura.h"
#include "StockController.h"

class FacturaController {
private:
    std::vector<Factura> facturas;
    StockController& stockController; // Referencia al controlador de Stock

public:
    // Constructor que recibe una referencia al controlador de Stock
    FacturaController(StockController& stockCtrl);

    // Agregar Factura
    bool agregarFactura(const Factura& factura);

    // Obtener Factura por ID
    Factura* obtenerFacturaPorId(int id);

    // Listar todas las Facturas
    std::vector<Factura> listarFacturas() const;
};

#endif // FACTURACONTROLLER_H
