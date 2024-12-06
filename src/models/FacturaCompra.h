// src/models/FacturaCompra.h
#ifndef FACTURACOMPRA_H
#define FACTURACOMPRA_H

#include "Factura.h"
#include "StockController.h"
#include <iostream>

extern StockController stockCtrl; // Declaración externa del controlador de stock

class FacturaCompra : public Factura {
public:
    // Constructor
    FacturaCompra(int id, const std::string& fecha, const std::string& hora,
                 int idEmpleado, int idCliente, int idProveedor)
        : Factura(id, fecha, hora, idEmpleado, idCliente, idProveedor) {}

    // Implementación del método virtual
    void procesar() override {
        // Incrementar stock según los detalles de la factura
        for (const auto& detalle : detalles) {
            stockCtrl.aumentarStock(detalle.getIdProducto(), detalle.getCantidadProductos());
        }
        // Otros procesos específicos de una factura de compra
        std::cout << "Factura de compra procesada (ID: " << idFactura << "). Stock incrementado.\n";
    }
};

#endif // FACTURACOMPRA_H
