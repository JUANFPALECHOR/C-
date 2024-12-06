#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>


class Producto {
private:
    int idProducto;                   
    std::string descripcionProducto;  
    int idMarca;                      
    double precio;                    

public:
    // Constructor
    Producto(int id, const std::string& descripcion, int idMarca, double precio);

    // Getters y Setters
    int getIdProducto() const;
    void setIdProducto(int id);

    std::string getDescripcionProducto() const;
    void setDescripcionProducto(const std::string& descripcion);

    int getIdMarca() const;
    void setIdMarca(int idMarca);

    double getPrecio() const;        
    void setPrecio(double precio);    
};

#endif 
