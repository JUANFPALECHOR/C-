#ifndef MARCA_VIEW_H
#define MARCA_VIEW_H

#include "../controllers/MarcaController.h"
#include "../utils/Validator.h"

class MarcaView {
public:
    MarcaView(MarcaController& marcaCtrl);
    void mostrarMenu();

private:
    MarcaController& marcaCtrl;

    void agregarMarca();
    void listarMarcas();
    void actualizarMarca();
    void eliminarMarca();
};

#endif 
