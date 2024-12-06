#ifndef REPORTEVIEW_H
#define REPORTEVIEW_H

#include "ReporteController.h"
#include "MarcaController.h"
#include "ProductoController.h"
#include <iostream>
#include <limits>

class ReporteView {
private:
    ReporteController& reporteController;
    MarcaController& marcaController;
    ProductoController& productoController;

public:
    // Constructor
    ReporteView(ReporteController& reporteCtrl, MarcaController& marcaCtrl, ProductoController& productoCtrl);

    // Método para mostrar el menú de reportes
    void mostrarMenuReportes();

    // Método para imprimir productos por marca
    void imprimirProductosPorMarca();
};

#endif // REPORTEVIEW_H
