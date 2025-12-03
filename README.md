# Tienda Virtual
Este proyecto es una simulación muy sencilla de una tienda virtual, con 3 clases basicas como `producto` , `comprador` , `carrito` el programa permitira crear algunos productos y un comprador luego simula el proceso de elegir productos y realizar una compra.
## Clases
- - Producto
-  Atributos: nombre, precio, cantidad.
-  Métodos: mostrar información y el precio.
-  Representa un artículo disponible para comprar.
-  - Comprador
   - Atributos: nombre y saldo disponible.
   - Métodos: mostrar información, verificar si puede pagar y realizar el pago.
   - Representa al usuario que realiza la compra.
- - Carrito
     -  Contiene los productos seleccionados por el comprador.
     -   Métodos: añadir productos, calcular total, mostrar el carrito.
     -   Representa los artículos que se desean adquirir.
-   - Inventario
      - Contiene hasta 50 productos.
      - Métodos: mostrar el inventario, buscar por nombre, conseguir el producto
  - - Tienda
    -  Administra el inventario y compra final
    -  Métodos: conseguir el inventario y procesar una compra
   
# Funcionamiento del Programa

Se inicializa la tienda y se cargan productos predefinidos.

- El usuario ingresa:

Su nombre

Su dinero (con validación segura)

- Menú disponible:

Ver inventario

Agregar productos al carrito

Ver el carrito y total

- Comprar

Al comprar:

Se verifica saldo suficiente.

Se descuenta saldo.

Se muestra cambio.

Se reduce la cantidad del producto en el inventario.

## Explicacion de codigos no visto en clase
`CONST`
- En este proyecto, `const` se utiliza para proteger datos, evitar modificaciones accidentales y hacer el programa más eficiente, especialmente al trabajar con objetos como Producto y Tienda.
- A continuación se explicare todos los usos de const presentes en mi código.

- - `const Producto&` : 
  - Producto& → se pasa por referencia (no se copia el objeto).
  - const → garantiza que la función no modificará el producto recibido.
- - `float getPrecio() const;` . . . :
  - Permite que los objetos `Producto` creados como constantes puedan usar estos métodos.
  - Hace la clase más segura y consistente.
- - `for (const auto& producto : inventario) {` :
  - Evita copiar cada producto.

    
   Diagrama de clases:
     <img width="2760" height="2994" alt="UML Proyecto FINAL" src="https://github.com/user-attachments/assets/d9ca083a-214f-4874-84b3-0d2ad2926f6b" />


## Instrucciones de compilación
`g++ main.cpp Tienda.cpp -o tienda`

## Instrucciones de ejecución
### Linux
`./tienda`
### Windows
`.\tienda.exe`
