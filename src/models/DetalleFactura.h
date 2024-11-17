#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H

// Definición de la clase DetalleFactura
// Esta clase representa un detalle dentro de una factura, donde se especifican
// los productos comprados, sus precios y la cantidad de cada producto.
class DetalleFactura {
private:
    // Atributos privados para almacenar la información del detalle de la factura
    int idDetalleFactura;   // Identificador único del detalle de la factura
    int idFactura;          // Identificador de la factura asociada a este detalle
    int idProducto;         // Identificador del producto incluido en la factura
    double valorProducto;   // Precio unitario del producto
    int cantidadProductos;  // Cantidad de unidades del producto incluidas en la factura

public:
    // Constructor de la clase DetalleFactura
    // Inicializa un objeto DetalleFactura con todos sus atributos
    // Parámetros:
    // - idDetalle: Identificador único para el detalle de la factura
    // - idFact: Identificador de la factura a la que pertenece este detalle
    // - idProd: Identificador del producto
    // - valor: Precio unitario del producto
    // - cantidad: Cantidad de productos
    DetalleFactura(int idDetalle, int idFact, int idProd, double valor, int cantidad);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del detalle de la factura
    int getIdDetalleFactura() const;

    // Establece un nuevo ID para el detalle de la factura
    void setIdDetalleFactura(int id);

    // Obtiene el ID de la factura asociada
    int getIdFactura() const;

    // Establece un nuevo ID para la factura
    void setIdFactura(int id);

    // Obtiene el ID del producto
    int getIdProducto() const;

    // Establece un nuevo ID para el producto
    void setIdProducto(int id);

    // Obtiene el valor unitario del producto
    double getValorProducto() const;

    // Establece un nuevo valor unitario para el producto
    void setValorProducto(double valor);

    // Obtiene la cantidad de productos
    int getCantidadProductos() const;

    // Establece una nueva cantidad de productos
    void setCantidadProductos(int cantidad);
};

#endif // DETALLEFACTURA_H
