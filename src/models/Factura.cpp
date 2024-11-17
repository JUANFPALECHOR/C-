#include "Factura.h"

// Implementación del constructor de la clase Factura
// Inicializa todos los atributos de la clase utilizando una lista de inicialización
// Parámetros:
// - id: Identificador único de la factura
// - fecha: Fecha en que se generó la factura
// - hora: Hora en que se generó la factura
// - tipo: Tipo de factura (COMPRA o VENTA)
// - idEmpleado: Identificador del empleado que generó la factura
// - idCliente: Identificador del cliente asociado a la factura
// - idProveedor: Identificador del proveedor relacionado con la factura
Factura::Factura(int id, const std::string& fecha, const std::string& hora,
                 TipoFactura tipo, int idEmpleado, int idCliente, int idProveedor)
    : idFactura(id), fechaFactura(fecha), horaFactura(hora),
      tipoFactura(tipo), idEmpleado(idEmpleado), idCliente(idCliente),
      idProveedor(idProveedor) {}

// Método para obtener el ID de la factura
// Retorna el ID como un entero
int Factura::getIdFactura() const {
    return idFactura;
}

// Método para establecer un nuevo ID para la factura
void Factura::setIdFactura(int id) {
    idFactura = id; // Asigna el nuevo ID al atributo 'idFactura'
}

// Método para obtener la fecha de la factura
// Retorna la fecha como un string
std::string Factura::getFechaFactura() const {
    return fechaFactura;
}

// Método para establecer una nueva fecha para la factura
void Factura::setFechaFactura(const std::string& fecha) {
    fechaFactura = fecha; // Asigna la nueva fecha al atributo 'fechaFactura'
}

// Método para obtener la hora de la factura
// Retorna la hora como un string
std::string Factura::getHoraFactura() const {
    return horaFactura;
}

// Método para establecer una nueva hora para la factura
void Factura::setHoraFactura(const std::string& hora) {
    horaFactura = hora; // Asigna la nueva hora al atributo 'horaFactura'
}

// Método para obtener el tipo de factura (COMPRA o VENTA)
// Retorna el tipo como un valor de la enumeración TipoFactura
TipoFactura Factura::getTipoFactura() const {
    return tipoFactura;
}

// Método para establecer un nuevo tipo de factura
void Factura::setTipoFactura(TipoFactura tipo) {
    tipoFactura = tipo; // Asigna el nuevo tipo al atributo 'tipoFactura'
}

// Método para obtener el ID del empleado asociado a la factura
// Retorna el ID del empleado como un entero
int Factura::getIdEmpleado() const {
    return idEmpleado;
}

// Método para establecer un nuevo ID para el empleado
void Factura::setIdEmpleado(int id) {
    idEmpleado = id; // Asigna el nuevo ID al atributo 'idEmpleado'
}

// Método para obtener el ID del cliente asociado a la factura
// Retorna el ID del cliente como un entero
int Factura::getIdCliente() const {
    return idCliente;
}

// Método para establecer un nuevo ID para el cliente
void Factura::setIdCliente(int id) {
    idCliente = id; // Asigna el nuevo ID al atributo 'idCliente'
}

// Método para obtener el ID del proveedor asociado a la factura
// Retorna el ID del proveedor como un entero
int Factura::getIdProveedor() const {
    return idProveedor;
}

// Método para establecer un nuevo ID para el proveedor
void Factura::setIdProveedor(int id) {
    idProveedor = id; // Asigna el nuevo ID al atributo 'idProveedor'
}

// Método para obtener la lista de detalles de la factura
// Retorna una referencia al vector de DetalleFactura
std::vector<DetalleFactura>& Factura::getDetalles() {
    return detalles;
}

// Método para añadir un nuevo detalle a la factura
// Parámetros:
// - detalle: Un objeto de tipo DetalleFactura que representa un producto en la factura
void Factura::addDetalle(const DetalleFactura& detalle) {
    detalles.push_back(detalle); // Agrega el nuevo detalle al vector 'detalles'
}
