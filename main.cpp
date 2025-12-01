#include <iostream>
#include <limits>
#include "Tienda.hpp"

using namespace std;

int leerEnteroSeguro() {
    int valor;
    while (true) {
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingresa un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

float leerFloatSeguro() {
    float valor;
    while (true) {
        cin >> valor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingresa un numero valido: ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

int main() {
    Tienda tienda;

    tienda.getInventario().agregar(Producto("The Legend of Zelda: The Wind Waker", 1200, 5));
    tienda.getInventario().agregar(Producto("Mario Kart World", 1799, 3));
    tienda.getInventario().agregar(Producto("Elden Ring", 1400, 4));
    tienda.getInventario().agregar(Producto("The Witcher III", 49, 7));
    tienda.getInventario().agregar(Producto("Constance", 300, 1));

    string nombre;
    float dinero;

    cout << "Ingresa tu nombre: ";
    getline(cin, nombre);

    cout << "Ingresa tu dinero: $";
    dinero = leerFloatSeguro();

    Comprador comprador(nombre, dinero);
    Carrito carrito;

    int opcion;
    do {
        cout << "\nMENU";
        cout << "\n 1) Ver inventario";
        cout << "\n 2) Agregar producto al carrito";
        cout << "\n 3) Ver carrito";
        cout << "\n 4) Comprar";
        cout << "\n 5) Salir";
        cout << "\n Opcion: ";

        opcion = leerEnteroSeguro();

        if (opcion == 1) {
            tienda.getInventario().mostrar();
        }

        else if (opcion == 2) {
            string nombreProd;
            cout << "\n Nombre exacto del producto: ";
            getline(cin, nombreProd);

            int index = tienda.getInventario().buscar(nombreProd);

            if (index == -1) {
                cout << " No existe ese producto \n";
            }
            else {
                Producto& p = tienda.getInventario().getProducto(index);
                if (p.getCantidad() == 0)
                    cout << " Ya no hay existencias \n";
                else {
                    carrito.agregar(index);
                    p.setCantidad(p.getCantidad() - 1);
                    cout << " Agregado al carrito \n";
                }
            }
        }

        else if (opcion == 3) {
            carrito.mostrar(tienda.getInventario());
        }

        else if (opcion == 4) {
            carrito.mostrar(tienda.getInventario());
            tienda.procesarCompra(carrito, comprador);
        }

    } while (opcion != 5);

    cout << "\n Gracias por visitar la tienda\n";

    return 0;
}

