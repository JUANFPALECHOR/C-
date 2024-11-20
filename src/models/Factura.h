#ifndef FACTURA_H
#define FACTURA_H

#include <string>
#include <vector>
#include "DetalleFactura.h"

// Enumeración que define el tipo de factura
// Puede ser de tipo COMPRA o VENTA
enum class TipoFactura { COMPRA, VENTA };

// Definición de la clase Factura
// Esta clase representa una factura con sus respectivos datos y detalles.
class Factura {
protected:
    // Atributos protegidos para almacenar la información de la factura
    int idFactura;                       // Identificador único de la factura
    std::string fechaFactura;            // Fecha en que se generó la factura
    std::string horaFactura;             // Hora en que se generó la factura
    TipoFactura tipoFactura;             // Tipo de la factura (COMPRA o VENTA)
    int idEmpleado;                      // Identificador del empleado que generó la factura
    int idCliente;                       // Identificador del cliente asociado
    int idProveedor;                     // Identificador del proveedor asociado
    std::vector<DetalleFactura> detalles; // Lista de detalles de la factura (productos incluidos)

public:
    // Constructor de la clase Factura
    // Inicializa todos los atributos de la factura
    // Parámetros:
    // - id: Identificador único de la factura
    // - fecha: Fecha de emisión de la factura
    // - hora: Hora de emisión de la factura
    // - tipo: Tipo de la factura (COMPRA o VENTA)
    // - idEmpleado: Identificador del empleado que generó la factura
    // - idCliente: Identificador del cliente
    // - idProveedor: Identificador del proveedor
    Factura(int id, const std::string& fecha, const std::string& hora,
            TipoFactura tipo, int idEmpleado, int idCliente, int idProveedor);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID de la factura
    int getIdFactura() const;

    // Establece un nuevo ID para la factura
    void setIdFactura(int id);

    // Obtiene la fecha de la factura
    std::string getFechaFactura() const;

    // Establece una nueva fecha para la factura
    void setFechaFactura(const std::string& fecha);

    // Obtiene la hora de la factura
    std::string getHoraFactura() const;

    // Establece una nueva hora para la factura
    void setHoraFactura(const std::string& hora);

    // Obtiene el tipo de la factura (COMPRA o VENTA)
    TipoFactura getTipoFactura() const;

    // Establece un nuevo tipo de factura
    void setTipoFactura(TipoFactura tipo);

    // Obtiene el ID del empleado que generó la factura
    int getIdEmpleado() const;

    // Establece un nuevo ID para el empleado
    void setIdEmpleado(int id);

    // Obtiene el ID del cliente asociado a la factura
    int getIdCliente() const;

    // Establece un nuevo ID para el cliente
    void setIdCliente(int id);

    // Obtiene el ID del proveedor asociado a la factura
    int getIdProveedor() const;

    // Establece un nuevo ID para el proveedor
    void setIdProveedor(int id);

    // Obtiene la lista de detalles de la factura
    const std::vector<DetalleFactura>& getDetalles() const;

    // Añade un nuevo detalle a la factura
    // Parámetros:
    // - detalle: Un objeto de tipo DetalleFactura que representa un producto en la factura
    void addDetalle(const DetalleFactura& detalle);
};

#endif // FACTURA_H
