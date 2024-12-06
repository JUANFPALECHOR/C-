// src/models/FacturaVenta.h
#ifndef FACTURAVENTA_H
#define FACTURAVENTA_H

#include "Factura.h"
#include "StockController.h"
#include <iostream>

extern StockController stockCtrl; // Declaración externa del controlador de stock

class FacturaVenta : public Factura {
public:
    // Constructor
    FacturaVenta(int id, const std::string& fecha, const std::string& hora,
                int idEmpleado, int idCliente)
        : Factura(id, fecha, hora, idEmpleado, idCliente, 0) {} // idProveedor no aplica para ventas

    // Implementación del método virtual
    void procesar() override {
        // Reducir stock según los detalles de la factura
        for (const auto& detalle : detalles) {
            if (!stockCtrl.reducirStock(detalle.getIdProducto(), detalle.getCantidadProductos())) {
                std::cout << "Error: No hay suficiente stock para el producto ID " 
                          << detalle.getIdProducto() << ".\n";
            }
        }
        // Otros procesos específicos de una factura de venta
        std::cout << "Factura de venta procesada (ID: " << idFactura << "). Stock reducido.\n";
    }
};

#endif // FACTURAVENTA_H
