#ifndef TIENDA_HPP
#define TIENDA_HPP

#include <string>
#include <iostream>

/*
 * Clase Usuario:
 * Representa un usuario básico con un nombre.
 * Sirve como clase base para Comprador.
 */
class Usuario {
protected:
    std::string nombre;

public:
    Usuario();
    Usuario(std::string);

    std::string getNombre() const;   // No modifica el objeto
    void setNombre(std::string);
};

/*
 * Clase Comprador:
 * Hereda de Usuario y agrega saldo.
 * Maneja pagos y validación de fondos.
 */
class Comprador : public Usuario {
private:
    float saldo;

public:
    Comprador();
    Comprador(std::string, float);

    float getSaldo() const;          // No modifica saldo
    bool puedePagar(float) const;    // Revisa si tiene fondos suficientes
    void pagar(float);
};

/*
 * Clase Producto:
 * Guarda nombre, precio y cantidad disponible.
 * Permite mostrar y actualizar existencias.
 */
class Producto {
private:
    std::string nombre;
    float precio;
    int cantidad;

public:
    Producto();
    Producto(std::string, float, int);

    std::string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    void setCantidad(int);
    void mostrar() const;
};

/*
 * Clase Inventario:
 * Almacena hasta 50 productos.
 * Permite agregarlos, buscarlos y obtener referencias.
 */
class Inventario {
private:
    Producto lista[50];
    int totalProductos;

public:
    Inventario();

    void agregar(Producto);
    void mostrar() const;
    int buscar(std::string);

    Producto& getProducto(int index);            // Modificable
    const Producto& getProducto(int index) const; // Solo lectura
};

/*
 * Clase Carrito:
 * Guarda índices de productos seleccionados.
 * No almacena objetos Producto, solo sus índices.
 */
class Carrito {
private:
    int productos[20];
    int totalCarrito;

public:
    Carrito();

    void agregar(int index);
    void mostrar(const Inventario&) const;

    int getTotalCarrito() const;
    int getIndex(int i) const;
};

/*
 * Clase Tienda:
 * Contiene un Inventario y permite procesar compras.
 */
class Tienda {
private:
    Inventario inventario;

public:
    Tienda();

    Inventario& getInventario();
    void procesarCompra(Carrito&, Comprador&);
};

#endif

