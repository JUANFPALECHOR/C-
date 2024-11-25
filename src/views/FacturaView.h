#ifndef FACTURAVIEW_H
#define FACTURAVIEW_H

#include "../controllers/FacturaController.h"
#include "../controllers/EmpleadoController.h"
#include "../controllers/ClienteController.h"
#include "../controllers/ProveedorController.h"
#include "../controllers/ProductoController.h"

class FacturaView {
public:
    FacturaView(FacturaController& facturaCtrl,
               EmpleadoController& empleadoCtrl,
               ClienteController& clienteCtrl,
               ProveedorController& proveedorCtrl,
               ProductoController& productoCtrl);
    void mostrarMenu();

private:
    FacturaController& facturaCtrl;
    EmpleadoController& empleadoCtrl;
    ClienteController& clienteCtrl;
    ProveedorController& proveedorCtrl;
    ProductoController& productoCtrl;

    void crearFacturaVenta();
    void crearFacturaCompra();
    void generarReporteTotalVentasMensuales();
    void generarReporteMesesConMayoresVentas();
};

#endif // FACTURAVIEW_H
