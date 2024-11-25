#ifndef DETALLEFACTURA_H
#define DETALLEFACTURA_H

class DetalleFactura {
private:
    int idDetalleFactura;
    int idFactura;
    int idProducto;
    double valorProducto;
    int cantidadProductos;

public:
    // Constructor
    DetalleFactura(int idDetalle, int idFact, int idProd, double valor, int cantidad);

    // Getters y Setters
    int getIdDetalleFactura() const;
    void setIdDetalleFactura(int id);

    int getIdFactura() const;
    void setIdFactura(int id);

    int getIdProducto() const;
    void setIdProducto(int id);

    double getValorProducto() const;
    void setValorProducto(double valor);

    int getCantidadProductos() const;
    void setCantidadProductos(int cantidad);

    // Método para calcular el subtotal
    double calcularSubtotal() const;
};

#endif // DETALLEFACTURA_H
