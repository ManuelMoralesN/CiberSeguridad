#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que agrupa funciones para aplicar distintos algoritmos de cifrado sobre archivos de texto.
 */
class Cifrador {
public:
    /**
     * @brief Constructor por defecto.
     */
    Cifrador() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Cifrador() = default;

    /**
     * @brief Aplica el cifrado C�sar sobre un archivo.
     *
     * Esta funci�n solicita el nombre del archivo, la clave para el cifrado C�sar y cifra el archivo de texto
     * con el algoritmo C�sar. El archivo cifrado se guarda en la carpeta `bin/DatosCif/` con el prefijo `cesar_`.
     */
    static void cifrarCesar();

    /**
     * @brief Descifra un archivo previamente cifrado con el algoritmo C�sar.
     *
     * Esta funci�n solicita el nombre del archivo cifrado y la clave usada para el cifrado C�sar y descifra el
     * archivo de texto. El archivo descifrado se guarda en la carpeta `bin/DatosCrudos/` con el prefijo `recuperado_`.
     */
    static void descifrarCesar();

    /**
     * @brief Aplica el cifrado XOR sobre un archivo.
     *
     * Esta funci�n solicita el nombre del archivo, la clave para el cifrado XOR, y cifra el archivo de texto
     * utilizando el algoritmo XOR con la clave proporcionada. El archivo cifrado se guarda en la carpeta `bin/DatosCif/`
     * con el prefijo `xor_`.
     */
    static void cifrarXOREncoder();

    /**
     * @brief Descifra un archivo previamente cifrado con el algoritmo XOR.
     *
     * Esta funci�n solicita el nombre del archivo cifrado y la clave utilizada para el cifrado XOR, y descifra el
     * archivo de texto. El archivo descifrado se guarda en la carpeta `bin/DatosCrudos/` con el prefijo `recuperado_`.
     */
    static void descifrarXOR();

    /**
     * @brief Aplica el cifrado Vigen�re sobre un archivo.
     *
     * Esta funci�n solicita el nombre del archivo, la clave para el cifrado Vigen�re, y cifra el archivo de texto
     * utilizando el algoritmo Vigen�re con la clave proporcionada. El archivo cifrado se guarda en la carpeta `bin/DatosCif/`
     * con el prefijo `vigenere_`.
     */
    static void cifrarVigenere();

    /**
     * @brief Descifra un archivo previamente cifrado con el algoritmo Vigen�re.
     *
     * Esta funci�n solicita el nombre del archivo cifrado y la clave utilizada para el cifrado Vigen�re, y descifra el
     * archivo de texto. El archivo descifrado se guarda en la carpeta `bin/DatosCrudos/` con el prefijo `recuperado_`.
     */
    static void descifrarVigenere();

    /**
     * @brief Aplica conversi�n a binario (ASCII) sobre un archivo.
     *
     * Esta funci�n cifra el contenido del archivo convirti�ndolo a su representaci�n binaria ASCII (de cada car�cter).
     * El archivo cifrado se guarda en la carpeta `bin/DatosCif/` con el prefijo `ascii_`.
     */
    static void cifrarAscii();

    /**
     * @brief Descifra un archivo previamente cifrado convirtiendo la representaci�n binaria a texto ASCII.
     *
     * Esta funci�n descifra un archivo que fue previamente cifrado usando la representaci�n binaria ASCII y lo
     * convierte de nuevo a texto. El archivo descifrado se guarda en la carpeta `bin/DatosCrudos/` con el prefijo `recuperado_`.
     */
    static void descifrarAscii();

    /**
     * @brief Aplica el cifrado DES sobre un archivo.
     *
     * Esta funci�n solicita el nombre del archivo y la clave de 8 caracteres para cifrar el archivo usando el algoritmo
     * DES. El archivo cifrado se guarda en la carpeta `bin/DatosCif/` con el prefijo `des_`.
     */
    static void cifrarDES();

    /**
     * @brief Descifra un archivo previamente cifrado con DES.
     *
     * Esta funci�n solicita el nombre del archivo cifrado y la clave de 8 caracteres utilizada para cifrar con DES,
     * y descifra el archivo de texto. El archivo descifrado se guarda en la carpeta `bin/DatosCrudos/` con el prefijo `recuperado_`.
     */
    static void descifrarDES();
};
