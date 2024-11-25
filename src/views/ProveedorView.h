#ifndef PROVEEDOR_VIEW_H
#define PROVEEDOR_VIEW_H

#include "../controllers/ProveedorController.h"

class ProveedorView {
public:
    ProveedorView(ProveedorController& proveedorCtrl);
    void mostrarMenu();

private:
    ProveedorController& proveedorCtrl;

    void agregarProveedor();
    void listarProveedores();
    void actualizarProveedor();
    void eliminarProveedor();
};

#endif // PROVEEDOR_VIEW_H
