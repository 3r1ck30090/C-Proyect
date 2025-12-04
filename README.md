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
 
    `LIMITS`
  - Esta librería proporciona `numeric_limits`, una utilidad que contiene información sobre los valores máximos y mínimos que pueden almacenar los tipos numéricos de C++.
  - Usado solo para limpiar el buffer de entrada en las funciones de lectura segura en (leerEnteroseguro y leerFloarSeguro)

  - - `cin.ignore(numeric_limits<streamsize>::max(), '\n');`  :
    - numeric_limits<streamsize>::max() → Obtiene la cantidad máxima de caracteres que streamsize puede representar.
    - cin.ignore(...) → Le indica a C++ que ignore todo lo que esté en el buffer hasta encontrar un salto de línea ('\n')
    - cin.clear() → elimina el estado de error.
    - cin.ignore(...) → borra toda la entrada incorrecta.

    Y con esto me evito que cuando el usuario llegue a coloctar un caracter invalido no se rompa el programa en un bucle infinito haciendo que el usuario coloque solo opciones validas (pasaba más con letras y caracteres especiales)

    - - `do:`
      - Se utiliza para crear un ciclo que siempre se ejecuta una vez antes de revisar su condición.
      - Es útil en menús (para no usar virtual), validación de datos o cualquier situación donde el código deba correr mínimo una vez.
    
   Diagrama de clases:
  
<img width="2849" height="2314" alt="UML Proyecto" src="https://github.com/user-attachments/assets/aae753fb-7387-43d0-aa0e-cf16dded91cd" />


## Instrucciones de compilación
`g++ main.cpp Tienda.cpp -o tienda`

## Instrucciones de ejecución
### Linux
`./tienda`
### Windows
`.\tienda.exe`
