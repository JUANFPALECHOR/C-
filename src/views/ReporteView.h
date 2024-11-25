#ifndef REPORTEVIEW_H
#define REPORTEVIEW_H

#include "ReporteController.h"
#include "MarcaController.h"
#include <iostream>
#include <limits>

class ReporteView {
private:
    ReporteController& reporteController;
    MarcaController& marcaController;

public:
    // Constructor
    ReporteView(ReporteController& reporteCtrl, MarcaController& marcaCtrl);

    // Método para mostrar el menú de reportes
    void mostrarMenuReportes();

    // Método para imprimir productos por marca
    void imprimirProductosPorMarca();
};

#endif // REPORTEVIEW_H
