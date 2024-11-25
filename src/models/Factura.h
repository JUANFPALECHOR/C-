#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <vector>
#include <memory>
#include "DetalleFactura.h"

// Enumeración que define el tipo de factura
enum class TipoFactura { COMPRA, VENTA };

// Estructura para manejar la fecha y hora
struct FechaHora {
    int dia;
    int mes;
    int año;
    int hora;
    int minuto;
    int segundo;
};

// Clase Factura
class Factura {
private:
    int idFactura;
    FechaHora fechaHora;
    TipoFactura tipoFactura;
    int idEmpleado;
    int idCliente;    // Solo se usa si es factura de venta
    int idProveedor;  // Solo se usa si es factura de compra
    std::vector<std::shared_ptr<DetalleFactura>> detalles;

public:
    // Constructor unificado para Factura (maneja tanto venta como compra)
    Factura(int id, const FechaHora& fechaHora, TipoFactura tipo, int idEmpleado,
            int idCliente = 0, int idProveedor = 0);

    // Getters y Setters
    int getIdFactura() const;
    void setIdFactura(int id);

    FechaHora getFechaHora() const;
    void setFechaHora(const FechaHora& fechaHora);

    TipoFactura getTipoFactura() const;
    void setTipoFactura(TipoFactura tipo);

    int getIdEmpleado() const;
    void setIdEmpleado(int id);

    int getIdCliente() const;    // Solo para facturas de venta
    void setIdCliente(int id);

    int getIdProveedor() const;  // Solo para facturas de compra
    void setIdProveedor(int id);

    const std::vector<std::shared_ptr<DetalleFactura>>& getDetalles() const;

    // Añadir un detalle a la factura
    void addDetalle(const std::shared_ptr<DetalleFactura>& detalle);

    // Calcular el total de la factura
    double calcularTotal() const;

    // Mostrar información de la factura
    void mostrarInfo() const;
};

#endif // FACTURA_H
