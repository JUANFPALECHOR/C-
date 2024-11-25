#ifndef FACTURACONTROLLER_H
#define FACTURACONTROLLER_H

#include <vector>
#include <memory>
#include "Factura.h"
#include "StockController.h"

class FacturaController {
private:
    std::vector<std::shared_ptr<Factura>> facturas;
    StockController& stockController;

public:
    // Constructor
    FacturaController(StockController& stockCtrl);

    // Crear Factura de Venta
    bool crearFacturaVenta(const std::shared_ptr<Factura>& factura);

    // Crear Factura de Compra
    bool crearFacturaCompra(const std::shared_ptr<Factura>& factura);

    // Obtener Factura por ID
    std::shared_ptr<Factura> obtenerFacturaPorId(int id);

    // Listar todas las Facturas
    std::vector<std::shared_ptr<Factura>> listarFacturas() const;

    // Generar el siguiente ID de Factura
    int generarSiguienteId() const;

    // Métodos de reporte
    double calcularTotalVentasMensuales(int mes, int año) const;
    std::vector<std::pair<int, double>> obtenerVentasPorMes(int año) const;
};

#endif // FACTURACONTROLLER_H
