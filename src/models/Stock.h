#ifndef STOCK_H
#define STOCK_H

// Definición de la clase Stock
// Esta clase representa el inventario de un producto, incluyendo su cantidad actual y el stock mínimo permitido.
class Stock {
private:
    // Atributos privados para almacenar la información del inventario
    int idStock;        // Identificador único del registro de stock
    int idProducto;     // Identificador del producto en el inventario
    int existencias;    // Cantidad actual de existencias del producto
    int stockMinimo;    // Nivel mínimo de stock permitido para el producto

public:
    // Constructor de la clase Stock
    // Inicializa un objeto Stock con su ID, ID de producto, existencias y stock mínimo
    // Parámetros:
    // - id: Identificador único del registro de stock
    // - idProd: Identificador del producto en el inventario
    // - exist: Cantidad actual de existencias
    // - stockMin: Nivel mínimo de stock permitido
    Stock(int id, int idProd, int exist, int stockMin);

    // Métodos Getters y Setters para acceder y modificar los atributos

    // Obtiene el ID del registro de stock
    int getIdStock() const;

    // Establece un nuevo ID para el registro de stock
    void setIdStock(int id);

    // Obtiene el ID del producto asociado en el inventario
    int getIdProducto() const;

    // Establece un nuevo ID para el producto asociado
    void setIdProducto(int id);

    // Obtiene la cantidad actual de existencias en el inventario
    int getExistencias() const;

    // Establece una nueva cantidad de existencias
    void setExistencias(int exist);

    // Obtiene el nivel mínimo de stock permitido
    int getStockMinimo() const;

    // Establece un nuevo nivel mínimo de stock
    void setStockMinimo(int stockMin);

    // Aquí puedes agregar otros métodos relevantes si es necesario.
};

#endif 
