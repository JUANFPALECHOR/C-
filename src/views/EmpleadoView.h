#ifndef EMPLEADOVIEW_H
#define EMPLEADOVIEW_H

#include "../controllers/EmpleadoController.h"

class EmpleadoView {
public:
    EmpleadoView(EmpleadoController& empleadoCtrl);
    void mostrarMenu();

private:
    EmpleadoController& empleadoCtrl;

    void agregarEmpleado();
    void listarEmpleados();
    void actualizarEmpleado();
    void eliminarEmpleado();
};

#endif // EMPLEADOVIEW_H
