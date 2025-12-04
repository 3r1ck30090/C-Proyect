/*
 * Proyecto Tienda Virtual
 * Erick Buendia Urbina
 * A01715505
 * 05/12/2025
 */

/**
 * Descripcion este es un proyecto para la clase de Pensamiento
 * Computacional Orientado a Objetos. Es un programa que srive
 * como una tienda virtual con productos y con un comprador
 * permite calcular el precio total de los productos y
 * poder agarrarlos para comprarlos poniendo un dinero
 * y nombre establecido 
*/

//Bibliotecas

#include <iostream>     // Para entrada y salida
#include <limits>       // Para validar entradas numéricas
#include "Tienda.hpp"   // Contiene todas las clases del proyecto

using namespace std;


/**
 * Valida que el usuario ingrese un número entero.
 * Si la entrada es inválida, limpia el buffer y vuelve a pedir el dato.
 * Evita que el programa falle al introducir letras o símbolos.
*/
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


/**
 * Igual que leerEnteroSeguro, pero para valores flotantes.
 * Garantiza que el dinero ingresado sea un número real válido.
*/
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


        // Inicialización de la tienda e inventario
      //* Se crea un objeto Tienda que contiene un Inventario.
      //* Se agregan productos iniciales para que el usuario tenga opciones.
     //
    Tienda tienda;

    tienda.getInventario().agregar(Producto("The Legend of Zelda", 1200, 5));
    tienda.getInventario().agregar(Producto("Mario Kart World", 1799, 3));
    tienda.getInventario().agregar(Producto("Elden Ring", 1400, 4));
    tienda.getInventario().agregar(Producto("The Witcher III", 49, 7));
    tienda.getInventario().agregar(Producto("Constance", 300, 1));

    string nombre;
    float dinero;

    // Solicitar datos al usuario
    /* Se pide el nombre y dinero inicial del comprador.
     * Se crea el objeto Comprador con esos datos.
     */
    
    cout << "Ingresa tu nombre: ";
    getline(cin, nombre);

    cout << "Ingresa tu dinero: $";
    dinero = leerFloatSeguro();

    Comprador comprador(nombre, dinero);
    Carrito carrito;


        /**
     * El menú permite: ver inventario,
     agregar productos al carrito,
     ver el carrito,
     Comprary Salir
     *
     * Se repite hasta que el usuario seleccione la opción 5.
    */
    int opcion;
    do {
        cout << "\n MENU";
        cout << "\n 1) Ver inventario";
        cout << "\n 2) Agregar producto al carrito";
        cout << "\n 3) Ver carrito";
        cout << "\n 4) Comprar";
        cout << "\n 5) Salir";
        cout << "\n Opcion: ";

        opcion = leerEnteroSeguro();
        /**
        Permite al usuario ver el inventario
        */
        if (opcion == 1) {
            tienda.getInventario().mostrar();
        }
        /**
         * El usuario escribe el nombre exacto del producto.
         * Si existe y tiene existencias, se agrega al carrito.
         * Se reduce la cantidad disponible en el inventario.
        */
        else if (opcion == 2) {
            string nombreProd;
            cout << "\n Nombre exacto del producto: ";
            getline(cin, nombreProd);

            int index = tienda.getInventario().buscar(nombreProd);
            /**
            Si una letra no coincide en la lista marcara error
            (por cierto index es solo para marcar el indice)
            */
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
        /**
         * Se muestran los productos agregados y el total acumulado.
        */
        else if (opcion == 3) {
            carrito.mostrar(tienda.getInventario());
        }
        /**
         * La tienda calcula el total del carrito.
         * Si el comprador tiene saldo suficiente, paga y se finaliza la compra.
        */
        else if (opcion == 4) {
            carrito.mostrar(tienda.getInventario());
            tienda.procesarCompra(carrito, comprador);
        }
        /**
        si el numero no marca algo entre 1-5 devuelve al inicio
        */
    } while (opcion != 5);

    cout << "\n Gracias por visitar la tienda\n";

    return 0;
}

