#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <string>
#include <iostream>

class Usuario {
protected:
    std::string nombre;
public:
    Usuario();
    Usuario(std::string);
    std::string getNombre() const;
    void setNombre(std::string);
};

class Comprador : public Usuario {
private:
    float saldo;
public:
    Comprador();
    Comprador(std::string, float);
    float getSaldo() const;
    bool puedePagar(float) const;
    void pagar(float);
};

class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;
public:
    Producto();
    Producto(std::string, float, int);
    std::string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    void setCantidad(int);
    void mostrar() const;
};

class Inventario {
private:
    Producto lista[50];
    int totalProductos;
public:
    Inventario();
    void agregar(Producto);
    void mostrar() const;
    int buscar(std::string);
    Producto& getProducto(int index);
    const Producto& getProducto(int index) const;
};

class Carrito {
private:
    int productos[20];
    int totalCarrito;
public:
    Carrito();
    void agregar(int index);
    void mostrar(const Inventario&) const;
    int getTotalCarrito() const;
    int getIndex(int i) const;
};

class Tienda {
private:
    Inventario inventario;
public:
    Tienda();
    Inventario& getInventario();
    void procesarCompra(Carrito&, Comprador&);
};

#endif
