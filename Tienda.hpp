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
class Inventario {
private:
    Producto lista[50];
    int numProductos = 0;

public:
    Inventario() {}

    void agregarProducto(Producto p) {
        if (numProductos < 50) {
            lista[numProductos++] = p;
        }
    }

    void mostrarInventario() {
        std::cout << "\nInventario:\n";
        for (int i = 0; i < numProductos; i++) {
            lista[i].mostrarInfo();
        }
    }
};
class Tienda {
private:
    Producto productos[50];
    int numProductos = 0;

    Comprador compradores[50];
    int numCompradores = 0;

public:
void procesarCompra(Carrito carrito, Comprador& comprador);
void agregarProducto(Producto p) {
    if (numProductos < 50) {
         productos[numProductos++] = p;
        }
    }
    void mostrarProductos() {
        std::cout << "\nProductos en Tienda:\n";
        for (int i = 0; i < numProductos; i++) {
            productos[i].mostrarInfo();
        }
    }

    void agregarComprador(Comprador c) {
        if (numCompradores < 50) {
            compradores[numCompradores++] = c;
        }
    }
    void mostrarCompradores() {
        std::cout << "\nCompradores registrados:\n";
        for (int i = 0; i < numCompradores; i++) {
            compradores[i].mostrarInfo();
        }
    }
};
#endif
