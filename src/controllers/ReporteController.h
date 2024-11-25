#ifndef REPORTECONTROLLER_H
#define REPORTECONTROLLER_H

#include <vector>
#include <memory>
#include <map>
#include "FacturaController.h"
#include "StockController.h"
#include "ClienteController.h"
#include "EmpleadoController.h"
#include "ProductoController.h"
#include "MarcaController.h"

class ReporteController {
private:
    FacturaController& facturaController;
    StockController& stockController;
    ClienteController& clienteController;
    EmpleadoController& empleadoController;
    ProductoController& productoController;
    MarcaController& marcaController;

public:
    // Constructor actualizado para aceptar todos los controladores necesarios
    ReporteController(FacturaController& facturaCtrl,
                      StockController& stockCtrl,
                      ClienteController& clienteCtrl,
                      EmpleadoController& empleadoCtrl,
                      ProductoController& productoCtrl,
                      MarcaController& marcaCtrl);

    // Métodos de reporte
    std::vector<std::shared_ptr<Factura>> mostrarFacturasDeVentasPorMes(int mes, int año) const;
    std::pair<int, double> mostrarEmpleadoConMasVentas(int año) const;
    std::map<int, double> calcularVentasMensuales() const;

    // Nuevo Método: Mostrar Productos por Marca
    std::vector<Producto> mostrarProductosPorMarca(int idMarca) const;
    
};

#endif // REPORTECONTROLLER_H
