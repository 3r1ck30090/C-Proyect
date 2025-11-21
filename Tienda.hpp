#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <iostream>
#include <string>

class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Producto(std::string n, float p, int c);

    std::string getNombre();
    float getPrecio();
    int getCantidad();

    void setNombre(std::string n);
    void setPrecio(float p);
    void setCantidad(int c);

    void mostrarInfo();
};

class Comprador {
private:
    std::string nombre;
    float saldo;

public:
    Comprador(std::string n, float s);

    std::string getNombre();
    float getSaldo();

    void setNombre(std::string n);
    void setSaldo(float s);

    bool puedePagar(float total);
    void pagar(float total);

    void mostrarInfo();
};

class Carrito {
private:
    Producto producto1;
    Producto producto2;
    float total;

public:
    Carrito(Producto p1, Producto p2);

    float getTotal();
    void mostrarCarrito();
};
class Tienda {
public:
    void procesarCompra(Carrito carrito, Comprador& comprador);
};

#endif

