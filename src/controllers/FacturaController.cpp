// FacturaController.cpp
#include "FacturaController.h"

FacturaController::FacturaController(StockController& stockCtrl)
    : stockController(stockCtrl) {}

bool FacturaController::agregarFactura(const Factura& factura) {
    // Verificar si el ID ya existe
    for (const auto& f : facturas) {
        if (f.getIdFactura() == factura.getIdFactura()) {
            return false; // ID duplicado
        }
    }

    // Actualizar stock según el tipo de factura
    if (factura.getTipoFactura() == TipoFactura::VENTA) {
        for (const auto& detalle : factura.getDetalles()) {
            stockController.reducirStock(detalle.getIdProducto(), detalle.getCantidadProductos());
        }
    } else if (factura.getTipoFactura() == TipoFactura::COMPRA) {
        for (const auto& detalle : factura.getDetalles()) {
            stockController.aumentarStock(detalle.getIdProducto(), detalle.getCantidadProductos());
        }
    }

    facturas.push_back(factura);
    return true;
}

Factura* FacturaController::obtenerFacturaPorId(int id) {
    for (auto& f : facturas) {
        if (f.getIdFactura() == id) {
            return &f;
        }
    }
    return nullptr;
}

std::vector<Factura> FacturaController::listarFacturas() const {
    return facturas;
}
