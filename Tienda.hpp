#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <iostream>
#include <string>
#include <vector>

class Usuario {
protected:
    std::string nombre;

public:
    Usuario();
    Usuario(std::string n);

    std::string getNombre();
    void setNombre(std::string n);
};

class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Producto();
    Producto(std::string n, float p, int c);

    std::string getNombre();
    float getPrecio();
    int getCantidad();

    void setNombre(std::string n);
    void setPrecio(float p);
    void setCantidad(int c);

    void mostrarInfo();
};

class Comprador : public Usuario {
private:
    float saldo;

public:
    Comprador();
    Comprador(std::string n, float s);

    float getSaldo();
    void setSaldo(float s);

    bool puedePagar(float total);
    void pagar(float total);

    void mostrarInfo();
};

class Inventario {
private:
    Producto lista[50];
    int numProductos = 0;

public:
    Inventario();

    void agregarProducto(Producto p);
    bool descontarProducto(std::string nombre);
    void mostrarInventario();
};

class Carrito {
private:
    std::vector<Producto> productos;
    float total;

public:
    Carrito();

    void agregar(Producto p);
    float getTotal();
    std::vector<Producto> getProductos();

    void mostrarCarrito();
};

class Tienda {
private:
    Inventario inventario;

public:
    Tienda();
    Tienda(Inventario inv);

    void agregarAlInventario(Producto p);
    void mostrarInventario();

    void procesarCompra(Carrito carrito, Comprador &comprador);
};

#endif
