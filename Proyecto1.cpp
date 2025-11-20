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
              << ", Cantidad: " << cantidad << std::endl;
}

Comprador::Comprador(std::string n, float s)
    : nombre(n), saldo(s) {}

std::string Comprador::getNombre() { return nombre; }
float Comprador::getSaldo() { return saldo; }

void Comprador::setNombre(std::string n) { nombre = n; }
void Comprador::setSaldo(float s) { saldo = s; }

void Comprador::mostrarInfo() {
    std::cout << "Comprador: " << nombre
              << ", Saldo disponible: $" << saldo << std::endl;
}

bool Comprador::puedePagar(float total) {
    return saldo >= total;
}

void Comprador::pagar(float total) {
    if (puedePagar(total)) {
        saldo -= total;
        std::cout << nombre << " ha pagado $" << total
                  << ". Nuevo saldo: $" << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente para realizar la compra." << std::endl;
    }
}

Carrito::Carrito(Producto p1, Producto p2)
    : producto1(p1), producto2(p2) {
    total = p1.getPrecio() + p2.getPrecio();
}

float Carrito::getTotal() { return total; }

void Carrito::mostrarCarrito() {
    std::cout << "\n--- Carrito de Compras ---\n";
    producto1.mostrarInfo();
    producto2.mostrarInfo();
    std::cout << "Total a pagar: $" << total << std::endl;
}

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
