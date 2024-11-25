#ifndef CLIENTE_VIEW_H
#define CLIENTE_VIEW_H

#include "../controllers/ClienteController.h"

class ClienteView {
public:
    ClienteView(ClienteController& clienteCtrl);
    void mostrarMenu();

private:
    ClienteController& clienteCtrl;

    void agregarCliente();
    void listarClientes();
    void actualizarCliente();
    void eliminarCliente();
};

#endif // CLIENTE_VIEW_H
