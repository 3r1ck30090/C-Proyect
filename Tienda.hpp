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
std::string getNombre() const;  // const: garantiza que no modifica el objeto
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
float getSaldo() const; // No modifica el saldo
bool puedePagar(float) const; // Revisa si el comprador tiene suficiente dinero
void pagar(float);
};
/*
 * Clase Producto:
 * Guarda nombre, precio y cantidad disponible.
 * Tiene métodos para mostrar y actualizar existencia.
 */
class Producto {
private:
std::string nombre;
float precio;
int cantidad;
public:
Producto();
Producto(std::string, float, int);
std::string getNombre() const;  // const: no cambia el producto
float getPrecio() const;
int getCantidad() const;
void setCantidad(int);
void mostrar() const;
};
/*
 * Clase Inventario:
 * Almacena hasta 50 productos.
 * Permite agregarlos, buscarlos y obtener referencias.
 (Un que no este en el menu lo deje de idea,
 quise que pudera restockearse solo 
 pero no supe como)
 * getProducto tiene dos versiones:
 * Producto& → permite modificar.
 * const Producto& → solo lectura.
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
Producto& getProducto(int index);
const Producto& getProducto(int index) const;
};
/*
 * Clase Carrito:
 * Guarda índices de productos seleccionados.
 * No almacena productos reales, solo referencias por índice.
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
 * Contiene un Inventario y realiza compras.
 * procesarCompra descuenta existencias y dinero del comprador.
 */
class Tienda {
private:
Inventario inventario;
public:
Tienda();
Inventario& getInventario();  // Retorna referencia para modificarlo
void procesarCompra(Carrito&, Comprador&);     
};

#endif

