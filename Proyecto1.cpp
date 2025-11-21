#include "Tienda.hpp"

Producto::Producto(std::string n, float p, int c)
    : nombre(n), precio(p), cantidad(c) {}

std::string Producto::getNombre() { return nombre; }
float Producto::getPrecio() { return precio; }
int Producto::getCantidad() { return cantidad; }

void Producto::setNombre(std::string n) { nombre = n; }
void Producto::setPrecio(float p) { precio = p; }
void Producto::setCantidad(int c) { cantidad = c; }

void Producto::mostrarInfo() {
    std::cout << "Producto: " << nombre
              << ", Precio: $" << precio
              << ", Cantidad: " << cantidad
              << std::endl;
}

Comprador::Comprador(std::string n, float s)
    : nombre(n), saldo(s) {}

std::string Comprador::getNombre() { return nombre; }
float Comprador::getSaldo() { return saldo; }

void Comprador::setNombre(std::string n) { nombre = n; }
void Comprador::setSaldo(float s) { saldo = s; }

bool Comprador::puedePagar(float total) {
    return saldo >= total;
}

void Comprador::pagar(float total) {
    saldo -= total;
}

void Comprador::mostrarInfo() {
    std::cout << "Comprador: " << nombre
              << ", Saldo disponible: $" << saldo
              << std::endl;
}

Carrito::Carrito(Producto p1, Producto p2)
    : producto1(p1), producto2(p2) {
    total = (p1.getPrecio() * p1.getCantidad()) +
            (p2.getPrecio() * p2.getCantidad());
}

float Carrito::getTotal() { return total; }

void Carrito::mostrarCarrito() {
    std::cout << "\n Carrito de Compras\n";
    producto1.mostrarInfo();
    producto2.mostrarInfo();
    std::cout << "Total a pagar: $" << total << std::endl;
}

void Tienda::procesarCompra(Carrito carrito, Comprador& comprador) {

    float total = carrito.getTotal();

    if (comprador.puedePagar(total)) {
        std::cout << "\nCompra exitosa.\n";
        comprador.pagar(total);
        std::cout << "Nuevo saldo: $" << comprador.getSaldo() << std::endl;
    } else {
        std::cout << "\nEl comprador no tiene saldo suficiente.\n";
    }
}
int main() {
    Producto p1("Laptop", 10000, 2);
    Producto p2("Mouse", 250, 5);

    Comprador cliente("Carlos", 15000);

    Carrito carrito(p1, p2);

    cliente.mostrarInfo();
    carrito.mostrarCarrito();

    Tienda tienda;
    tienda.procesarCompra(carrito, cliente);

    return 0;
}
