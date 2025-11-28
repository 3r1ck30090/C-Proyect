#include "Tienda.hpp"
#include <iostream>

Usuario::Usuario() : nombre("Sin nombre") {}
Usuario::Usuario(std::string n) : nombre(n) {}

std::string Usuario::getNombre() { return nombre; }
void Usuario::setNombre(std::string n) { nombre = n; }

Producto::Producto() : nombre(""), precio(0), cantidad(0) {}

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
              << " | Precio: $" << precio
              << " | Cantidad: " << cantidad << "\n";
}

Comprador::Comprador() : Usuario(), saldo(0) {}

Comprador::Comprador(std::string n, float s)
    : Usuario(n), saldo(s) {}

float Comprador::getSaldo() { return saldo; }
void Comprador::setSaldo(float s) { saldo = s; }

bool Comprador::puedePagar(float total) { return saldo >= total; }
void Comprador::pagar(float total) { saldo -= total; }

void Comprador::mostrarInfo() {
    std::cout << "Comprador: " << nombre
              << " | Saldo: $" << saldo << "\n";
}

Inventario::Inventario() {}

void Inventario::agregarProducto(Producto p) {
    if (numProductos < 50)
        lista[numProductos++] = p;
}

bool Inventario::descontarProducto(std::string nombre) {
    for (int i = 0; i < numProductos; i++) {
        if (lista[i].getNombre() == nombre) {

            int nueva = lista[i].getCantidad() - 1;

            if (nueva <= 0) {
                for (int j = i; j < numProductos - 1; j++)
                    lista[j] = lista[j + 1];
                numProductos--;
            } else {
                lista[i].setCantidad(nueva);
            }

            return true;
        }
    }
    return false;
}

void Inventario::mostrarInventario() {
    std::cout << "\n- INVENTARIO -\n";
    for (int i = 0; i < numProductos; i++)
        lista[i].mostrarInfo();
}

Carrito::Carrito() : total(0) {}

void Carrito::agregar(Producto p) {
    productos.push_back(p);
    total += p.getPrecio() * p.getCantidad();
}

float Carrito::getTotal() { return total; }

std::vector<Producto> Carrito::getProductos() { return productos; }

void Carrito::mostrarCarrito() {
    std::cout << "\n- CARRITO -\n";
    for (auto &p : productos)
        p.mostrarInfo();

    std::cout << "TOTAL: $" << total << "\n";
}

Tienda::Tienda() {}

Tienda::Tienda(Inventario inv) : inventario(inv) {}

void Tienda::agregarAlInventario(Producto p) {
    inventario.agregarProducto(p);
}

void Tienda::mostrarInventario() {
    inventario.mostrarInventario();
}

void Tienda::procesarCompra(Carrito carrito, Comprador &comprador) {

    float total = carrito.getTotal();

    if (!comprador.puedePagar(total)) {
        std::cout << "\nSaldo insuficiente.\n";
        return;
    }

    comprador.pagar(total);

    for (auto &p : carrito.getProductos())
        inventario.descontarProducto(p.getNombre());

    std::cout << "\nCompra exitosa.\nNuevo saldo: $"
              << comprador.getSaldo() << "\n";
}

