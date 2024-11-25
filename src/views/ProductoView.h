#ifndef PRODUCTO_VIEW_H
#define PRODUCTO_VIEW_H

#include "../controllers/ProductoController.h"
#include "../controllers/MarcaController.h"

class ProductoView {
public:
    ProductoView(ProductoController& productoCtrl, MarcaController& marcaCtrl);
    void mostrarMenu();

private:
    ProductoController& productoCtrl;
    MarcaController& marcaCtrl;

    void agregarProducto();
    void listarProductos();
    void actualizarProducto();
    void eliminarProducto();
};

#endif // PRODUCTO_VIEW_H
