#include "Tienda.hpp"
using namespace std;

Usuario::Usuario() : nombre("Sin nombre") {}
Usuario::Usuario(string n) : nombre(n) {}

string Usuario::getNombre() const { return nombre; }
void Usuario::setNombre(string n) { nombre = n; }

Comprador::Comprador() : Usuario(), saldo(0) {}
Comprador::Comprador(string n, float s) : Usuario(n), saldo(s) {}

float Comprador::getSaldo() const { return saldo; }
bool Comprador::puedePagar(float total) const { return saldo >= total; }
void Comprador::pagar(float total) { saldo -= total; }

Producto::Producto() : nombre(""), precio(0), cantidad(0) {}
Producto::Producto(string n, float p, int c) : nombre(n), precio(p), cantidad(c) {}

string Producto::getNombre() const { return nombre; }
float Producto::getPrecio() const { return precio; }
int Producto::getCantidad() const { return cantidad; }
void Producto::setCantidad(int c) { cantidad = c; }

void Producto::mostrar() const {
    cout << nombre << " - $" << precio << " (" << cantidad << " disponibles)\n";
}

Inventario::Inventario() : totalProductos(0) {}

void Inventario::agregar(Producto p) {
    if (totalProductos < 50)
        lista[totalProductos++] = p;
}

void Inventario::mostrar() const {
    cout << "\n INVENTARIO \n";
    for (int i = 0; i < totalProductos; i++)
        lista[i].mostrar();
}

int Inventario::buscar(string n) {
    for (int i = 0; i < totalProductos; i++)
        if (lista[i].getNombre() == n)
            return i;
    return -1;
}

Producto& Inventario::getProducto(int index) {
    return lista[index];
}
const Producto& Inventario::getProducto(int index) const {
    return lista[index];
}
Carrito::Carrito() : totalCarrito(0) {}

void Carrito::agregar(int index) {
    if (totalCarrito < 20)
        productos[totalCarrito++] = index;
}

void Carrito::mostrar(const Inventario& inventario) const {
    cout << "\nCARRITO\n";

    float suma = 0;

    for (int i = 0; i < totalCarrito; i++) {
        int idx = productos[i];
        inventario.getProducto(idx).mostrar();
        suma += inventario.getProducto(idx).getPrecio();
    }

    cout << "TOTAL: $" << suma << "\n";
}

int Carrito::getTotalCarrito() const {
    return totalCarrito;
}

int Carrito::getIndex(int i) const {
    return productos[i];
}

Tienda::Tienda() {}

Inventario& Tienda::getInventario() {
    return inventario;
}

void Tienda::procesarCompra(Carrito& carrito, Comprador& comprador) {
    float total = 0;

    for (int i = 0; i < carrito.getTotalCarrito(); i++) {
        int idx = carrito.getIndex(i);
        total += inventario.getProducto(idx).getPrecio();
    }

    if (!comprador.puedePagar(total)) {
        cout << "\n No tienes suficiente dinero\n";
        return;
    }

    comprador.pagar(total);

    cout << "\n Compra realizada\n";
    cout << "Tu cambio es: $" << comprador.getSaldo() << "\n";
}

