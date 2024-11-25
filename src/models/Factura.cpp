#include "Factura.h"
#include <iostream>

// Constructor unificado
Factura::Factura(int id, const FechaHora& fechaHora, TipoFactura tipo, int idEmpleado,
               int idCliente, int idProveedor)
    : idFactura(id), fechaHora(fechaHora), tipoFactura(tipo),
      idEmpleado(idEmpleado), idCliente(idCliente), idProveedor(idProveedor) {}

// Getters y Setters
int Factura::getIdFactura() const { return idFactura; }
void Factura::setIdFactura(int id) { idFactura = id; }

FechaHora Factura::getFechaHora() const { return fechaHora; }
void Factura::setFechaHora(const FechaHora& fh) { fechaHora = fh; }

TipoFactura Factura::getTipoFactura() const { return tipoFactura; }
void Factura::setTipoFactura(TipoFactura tipo) { tipoFactura = tipo; }

int Factura::getIdEmpleado() const { return idEmpleado; }
void Factura::setIdEmpleado(int id) { idEmpleado = id; }

int Factura::getIdCliente() const { return idCliente; }
void Factura::setIdCliente(int id) { idCliente = id; }

int Factura::getIdProveedor() const { return idProveedor; }
void Factura::setIdProveedor(int id) { idProveedor = id; }

const std::vector<std::shared_ptr<DetalleFactura>>& Factura::getDetalles() const { return detalles; }

// Añadir un detalle a la factura
void Factura::addDetalle(const std::shared_ptr<DetalleFactura>& detalle) {
    detalles.push_back(detalle);
}

// Calcular el total de la factura
double Factura::calcularTotal() const {
    double total = 0.0;
    for (const auto& detalle : detalles) {
        total += detalle->calcularSubtotal();
    }
    return total;
}

// Mostrar información de la factura
void Factura::mostrarInfo() const {
    std::cout << "ID Factura: " << idFactura << "\n";
    std::cout << "Fecha: " << fechaHora.dia << "/" << fechaHora.mes << "/" << fechaHora.año << "\n";
    std::cout << "Hora: " << fechaHora.hora << ":" << fechaHora.minuto << ":" << fechaHora.segundo << "\n";
    std::cout << "Tipo: " << (tipoFactura == TipoFactura::VENTA ? "Venta" : "Compra") << "\n";
    std::cout << "Empleado ID: " << idEmpleado << "\n";
    if (tipoFactura == TipoFactura::VENTA) {
        std::cout << "Cliente ID: " << idCliente << "\n";
    } else {
        std::cout << "Proveedor ID: " << idProveedor << "\n";
    }
    std::cout << "Detalles:\n";
    for (const auto& detalle : detalles) {
        std::cout << "  - Producto ID: " << detalle->getIdProducto()
                  << ", Cantidad: " << detalle->getCantidadProductos()
                  << ", Valor Unitario: $" << detalle->getValorProducto()
                  << ", Subtotal: $" << detalle->calcularSubtotal() << "\n";
    }
    std::cout << "Total Factura: $" << calcularTotal() << "\n";
}
