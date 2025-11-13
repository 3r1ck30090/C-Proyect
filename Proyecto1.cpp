#include <iostream>
class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Producto(std::string n, float p, int c) {
        nombre = n;
        precio = p;
        cantidad = c;
    }

    std::string getNombre() {
        return nombre;
    }

    float getPrecio() {
        return precio;
    }

    int getCantidad() {
        return cantidad;
    }

    void setNombre(std::string n) {
        nombre = n;
    }

    void setPrecio(float p) {
        precio = p;
    }

    void setCantidad(int c) {
        cantidad = c;
    }

    void mostrarInfo() {
        std::cout << "Producto: " << nombre
                  << ", Precio: $" << precio
                  << ", Cantidad: " << cantidad << std::endl;
    }
};

class Comprador {
private:
    std::string nombre;
    float saldo;

public:
    Comprador(std::string n, float s) {
        nombre = n;
        saldo = s;
    }

    std::string getNombre() {
        return nombre;
    }

    float getSaldo() {
        return saldo;
    }

    void setNombre(std::string n) {
        nombre = n;
    }

    void setSaldo(float s) {
        saldo = s;
    }

    void mostrarInfo() {
        std::cout << "Comprador: " << nombre
                  << ", Saldo disponible: $" << saldo << std::endl;
    }

    bool puedePagar(float total) {
        return saldo >= total;
    }

    void pagar(float total) {
        if (puedePagar(total)) {
            saldo = saldo - total;
            std::cout << nombre << " ha pagado $" << total
                      << ". Nuevo saldo: $" << saldo << std::endl;
        } else {
            std::cout << "Saldo insuficiente para realizar la compra." << std::endl;
        }
    }
};

class Carrito {
private:
    Producto producto1;
    Producto producto2;
    float total;

public:
    Carrito(Producto p1, Producto p2) : producto1(p1), producto2(p2) {
        total = p1.getPrecio() + p2.getPrecio();
    }

    float getTotal() {
        return total;
    }

    void mostrarCarrito() {
        std::cout << " Carrito de Compras" << std::endl;
        producto1.mostrarInfo();
        producto2.mostrarInfo();
        std::cout << "Total a pagar: $" << total << std::endl;
    }
};

int main() {
    Producto producto1("Laptop", 9999.99, 3);
    Producto producto2("Mouse", 249.50, 10);

    Comprador comprador1("Carlos", 12000.0);

    Carrito carrito(producto1, producto2);

    comprador1.mostrarInfo();
    carrito.mostrarCarrito();

    comprador1.pagar(carrito.getTotal());

    return 0;
}

