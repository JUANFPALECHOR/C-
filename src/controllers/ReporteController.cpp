#include "ReporteController.h"
#include <iostream>

// Constructor actualizado
ReporteController::ReporteController(FacturaController& facturaCtrl,
                                     StockController& stockCtrl,
                                     ClienteController& clienteCtrl,
                                     EmpleadoController& empleadoCtrl,
                                     ProductoController& productoCtrl,
                                     MarcaController& marcaCtrl)
    : facturaController(facturaCtrl),
      stockController(stockCtrl),
      clienteController(clienteCtrl),
      empleadoController(empleadoCtrl),
      productoController(productoCtrl),
      marcaController(marcaCtrl) {
    // Inicialización adicional si es necesaria
}

// Implementación de los métodos de reporte...

// Ejemplo: Mostrar Facturas de Ventas por Mes
std::vector<std::shared_ptr<Factura>> ReporteController::mostrarFacturasDeVentasPorMes(int mes, int año) const {
    std::vector<std::shared_ptr<Factura>> facturasFiltradas;

    for (const auto& factura : facturaController.listarFacturas()) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            FechaHora fecha = factura->getFechaHora();
            if (fecha.mes == mes && fecha.año == año) {
                facturasFiltradas.push_back(factura);
            }
        }
    }

    return facturasFiltradas;
}

// Ejemplo: Mostrar Empleado con Más Ventas en un Año
std::pair<int, double> ReporteController::mostrarEmpleadoConMasVentas(int año) const {
    std::map<int, double> ventasPorEmpleado;

    for (const auto& factura : facturaController.listarFacturas()) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            FechaHora fecha = factura->getFechaHora();
            if (fecha.año == año) {
                int idEmpleado = factura->getIdEmpleado();
                ventasPorEmpleado[idEmpleado] += factura->calcularTotal();
            }
        }
    }

    // Encontrar el empleado con mayor ventas
    int empleadoMax = -1;
    double ventasMax = 0.0;

    for (const auto& [empleado, ventas] : ventasPorEmpleado) {
        if (ventas > ventasMax) {
            ventasMax = ventas;
            empleadoMax = empleado;
        }
    }

    return {empleadoMax, ventasMax};
}

std::vector<Producto> ReporteController::mostrarProductosPorMarca(int idMarca) const {
    return productoController.obtenerProductosPorMarca(idMarca);
}

// Ejemplo: Calcular Ventas Mensuales
std::map<int, double> ReporteController::calcularVentasMensuales() const {
    std::map<int, double> ventasPorMes;

    for (const auto& factura : facturaController.listarFacturas()) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            FechaHora fecha = factura->getFechaHora();
            ventasPorMes[fecha.mes] += factura->calcularTotal();
        }
    }

    return ventasPorMes;

    
}
