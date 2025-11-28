#include <iostream>
#include "Tienda.hpp"

using namespace std;

int main() {

    Inventario inventario;

    inventario.agregarProducto(Producto("The Legend of Zelda: Breath of the Wild", 1299.0, 10));
    inventario.agregarProducto(Producto("Elden Ring", 1399.0, 7));
    inventario.agregarProducto(Producto("God of War Ragnarok", 1499.0, 5));
    inventario.agregarProducto(Producto("Overwatch", 999.0, 20));

    cout << "\n= CATALOGO INICIAL =\n";
    inventario.mostrarInventario();

    Comprador comprador("Miguel", 5000);

    Carrito carrito;
    carrito.agregar(Producto("Elden Ring", 1399.0f, 1));
    carrito.agregar(Producto("FIFA 24", 999.0f, 2));

    cout << "\n= CARRITO =\n";
    carrito.mostrarCarrito();

    Tienda tienda(inventario);

    tienda.agregarAlInventario(Producto("Spider-Man 2", 1499.0f, 12));

    cout << "\n= INVENTARIO ACTUALIZADO =\n";
    tienda.mostrarInventario();

    tienda.procesarCompra(carrito, comprador);

    cout << "\n= FIN =\n";

    return 0;
}

