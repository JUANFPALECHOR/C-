#include "FacturaController.h"
#include <algorithm>
#include <sstream>
#include <map>
#include <iostream>  // Para mensajes de depuración (opcional)

FacturaController::FacturaController(StockController& stockCtrl)
    : stockController(stockCtrl) {
}

// Crear Factura de Venta
bool FacturaController::crearFacturaVenta(const std::shared_ptr<Factura>& factura) {
    // Validar y actualizar stock (reducir existencias)
    for (const auto& detalle : factura->getDetalles()) {
        if (!stockController.reducirStock(detalle->getIdProducto(), detalle->getCantidadProductos())) {
            // Error al reducir stock (stock insuficiente)
            std::cerr << "Error: Stock insuficiente para el producto ID " << detalle->getIdProducto() << ".\n";
            return false;
        }
    }
    // Agregar factura a la lista
    facturas.push_back(factura);
    return true;
}

// Crear Factura de Compra
bool FacturaController::crearFacturaCompra(const std::shared_ptr<Factura>& factura) {
    // Validar y actualizar stock (aumentar existencias)
    for (const auto& detalle : factura->getDetalles()) {
        if (!stockController.aumentarStock(detalle->getIdProducto(), detalle->getCantidadProductos())) {
            // Error al aumentar stock
            std::cerr << "Error: No se pudo aumentar el stock para el producto ID " << detalle->getIdProducto() << ".\n";
            return false;
        }
    }
    // Agregar factura a la lista
    facturas.push_back(factura);
    return true;
}

// Obtener Factura por ID
std::shared_ptr<Factura> FacturaController::obtenerFacturaPorId(int id) {
    for (const auto& factura : facturas) {
        if (factura->getIdFactura() == id) {
            return factura;
        }
    }
    return nullptr; // No encontrada
}

// Listar todas las Facturas
std::vector<std::shared_ptr<Factura>> FacturaController::listarFacturas() const {
    return facturas;
}

int FacturaController::generarSiguienteId() const {
    if (facturas.empty()) {
        return 1;
    } else {
        return (*std::max_element(facturas.begin(), facturas.end(),
            [](const std::shared_ptr<Factura>& a, const std::shared_ptr<Factura>& b) {
                return a->getIdFactura() < b->getIdFactura();
            }))->getIdFactura() + 1;
    }
}

// Métodos de reporte

double FacturaController::calcularTotalVentasMensuales(int mes, int año) const {
    double total = 0.0;
    for (const auto& factura : facturas) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            const FechaHora& fh = factura->getFechaHora();
            if (fh.mes == mes && fh.año == año) {
                total += factura->calcularTotal();
            }
        }
    }
    return total;
}

std::vector<std::pair<int, double>> FacturaController::obtenerVentasPorMes(int año) const {
    std::map<int, double> ventasPorMes; // clave: mes, valor: total ventas

    for (const auto& factura : facturas) {
        if (factura->getTipoFactura() == TipoFactura::VENTA) {
            const FechaHora& fh = factura->getFechaHora();
            if (fh.año == año) {
                ventasPorMes[fh.mes] += factura->calcularTotal();
            }
        }
    }

    // Convertir el mapa a un vector de pares para facilitar el procesamiento
    std::vector<std::pair<int, double>> resultado;
    for (const auto& [mes, total] : ventasPorMes) {
        resultado.emplace_back(mes, total);
    }
    return resultado;
}
