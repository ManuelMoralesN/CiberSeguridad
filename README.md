# Manual de Usuario - Proyecto de Cifrado

## Descripción

Este proyecto implementa varios algoritmos de **cifrado y descifrado**:

- **César**
- **XOR**
- **Vigenère**
- **ASCII Binario**
- **DES**

## Requisitos

### Software necesario:

- C++17 o superior
- Un compilador compatible 

### Archivos requeridos:

- **main.cpp**: El archivo principal que contiene el menú interactivo para elegir el cifrado/descifrado.
- **Cifrador.cpp** y **Cifrador.h**: Implementación y declaración de las funciones de cifrado y descifrado.
- **Cesarin.h** y **Cesarin.cpp**: Gestión de archivos y rutas.
- **CesarEncryption.h**: Implementación del cifrado César.
- **XOREncoder.h**: Implementación del cifrado XOR.
- **Vigenere.h**: Implementación del cifrado Vigenère.
- **AsciiBinary.h**: Implementación de la conversión entre texto y binario (ASCII).
- **DES.h**: Implementación del algoritmo DES.

## Instrucciones de Uso

### 1. Compilación del proyecto
## 2. Ejecuta el programa
## 3. Menú de Opciones
El programa mostrará el siguiente menú interactivo para elegir el algoritmo que deseas usar:
```bash
======= MENÚ DE CIFRADO Y DESCIFRADO =======
1. Cifrar con César
2. Descifrar con César
3. Cifrar con XOR
4. Descifrar con XOR
5. Cifrar con Vigenère
6. Descifrar con Vigenère
7. Cifrar con ASCII Binario
8. Descifrar con ASCII Binario
9. Cifrar con DES
10. Descifrar con DES
0. Salir
Seleccione una opción:
```
## 4. Cifrado y Descifrado con los Algoritmos
**Cifrado César**
-Clave: Un número entero (por ejemplo, 3).

-Proceso: Desplaza cada letra del texto según el número de la clave.

Uso:

-Cifrar: Opción 1, ingresa el archivo y la clave.

-Descifrar: Opción 2, ingresa el archivo y la misma clave.

**Cifrado XOR**
-Clave: Una cadena de texto (por ejemplo, "claveX").

-Proceso: Realiza una operación XOR entre el texto y la clave.

Uso:

-Cifrar: Opción 3, ingresa el archivo y la clave.

-Descifrar: Opción 4, ingresa el archivo y la misma clave.

**Cifrado Vigenère**
-Clave: Una palabra (solo letras).

-Proceso: Cada letra del texto se cifra con una letra correspondiente de la clave.

Uso:

-Cifrar: Opción 5, ingresa el archivo y la clave.

-Descifrar: Opción 6, ingresa el archivo y la misma clave.

**Cifrado ASCII Binario**
-Proceso: Convierte el texto en su representación binaria (ASCII).

Uso:

-Cifrar: Opción 7, ingresa el archivo.

-Descifrar: Opción 8, ingresa el archivo cifrado.

**Cifrado DES**
-Clave: 8 caracteres (64 bits).

-Proceso: Cifra el texto en bloques de 64 bits utilizando DES.

Uso:

-Cifrar: Opción 9, ingresa el archivo y la clave.

-Descifrar: Opción 10, ingresa el archivo cifrado y la misma clave.

