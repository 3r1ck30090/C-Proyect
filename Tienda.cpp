#include "Tienda.hpp"
using namespace std;
/*
 * Usuario
 * Clase base con un nombre. Se usa para crear compradores.
 * Tiene constructor por defecto y uno con nombre.
 */
Usuario::Usuario() : nombre("Sin nombre") {}
Usuario::Usuario(string n) : nombre(n) {}

string Usuario::getNombre() const { return nombre; }  // const: para no altera el objeto
void Usuario::setNombre(string n) { nombre = n; }
/*
 * Comprador
 * Hereda de Usuario y añade un saldo.
 * Puede verificar si tiene dinero suficiente y pagar.
 */
Comprador::Comprador() : Usuario(), saldo(0) {}
Comprador::Comprador(string n, float s) : Usuario(n), saldo(s) {}

float Comprador::getSaldo() const { return saldo; }
bool Comprador::puedePagar(float total) const { return saldo >= total; }
void Comprador::pagar(float total) { saldo -= total; }
/*
 *Comprador
 * Hereda de Usuario y añade un saldo.
 * Puede verificar si tiene dinero suficiente y pagar.
 */
Producto::Producto() : nombre(""), precio(0), cantidad(0) {}
Producto::Producto(string n, float p, int c) : nombre(n), precio(p), cantidad(c) {}

string Producto::getNombre() const { return nombre; }
float Producto::getPrecio() const { return precio; }
int Producto::getCantidad() const { return cantidad; }
void Producto::setCantidad(int c) { cantidad = c; }

void Producto::mostrar() const {
    cout << nombre << " - $" << precio << " (" << cantidad << " disponibles)\n";
}
/*
 * Inventario
 * Guarda hasta 50 productos.
 * Permite buscarlos y obtener referencias.
 * Y permitia agregarlos
 */
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
            return i; // índice del producto encontrado
    return -1;  // no encontrado
}

Producto& Inventario::getProducto(int index) {
    return lista[index]; // permite modificar el producto
}
const Producto& Inventario::getProducto(int index) const {
    return lista[index]; // solo lectura
}
/*
 * Carrito
 * Guarda hasta 20 índices de productos seleccionados.
 * Muestra su contenido sumando el precio.
 */
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
/*
 * Tienda 
 * Contiene un inventario y gestiona las compras.
 * procesarCompra descuenta saldo y verifica fondos.
 */
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


