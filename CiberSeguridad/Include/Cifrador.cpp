#include "Cifrador.h"
#include "Cesarin.h"
#include "CesarEncryption.h"
#include "XOREncoder.h"
#include "Vigenere.h"
#include "AsciiBinary.h"
#include "DES.h" 

void Cifrador::cifrarCesar() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo a cifrar: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCruda(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCifrada("cesar_" + nombreArchivo);

    int clave = 0;
    std::cout << "Ingrese la clave numerica para el cifrado Cesar: ";
    std::cin >> clave;
    std::cin.ignore();

    std::string textoOriginal = Cesarin::leerArchivo(rutaEntrada);
    if (textoOriginal.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }

    CesarEncryption cesar;
    std::string textoCifrado = cesar.encode(textoOriginal, clave);

    if (Cesarin::guardarArchivo(rutaSalida, textoCifrado)) {
        std::cout << "Archivo cifrado guardado correctamente en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo cifrado.\n";
    }
}
/**
 * @brief Descifra un archivo previamente cifrado con el algoritmo César.
 */
void Cifrador::descifrarCesar() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo cifrado: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCifrada(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCruda("recuperado_" + nombreArchivo);

    int clave = 0;
    std::cout << "Ingrese la clave numerica usada para el cifrado: ";
    std::cin >> clave;
    std::cin.ignore();

    std::string textoCifrado = Cesarin::leerArchivo(rutaEntrada);
    if (textoCifrado.empty()) {
        std::cout << "No se pudo leer el archivo cifrado o esta vacio.\n";
        return;
    }

    CesarEncryption cesar;
    std::string textoDescifrado = cesar.decode(textoCifrado, clave);

    if (Cesarin::guardarArchivo(rutaSalida, textoDescifrado)) {
        std::cout << "Archivo descifrado guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo descifrado.\n";
    }
}
/**
 * @brief Cifra un archivo usando el algoritmo XOR.
 */
void Cifrador::cifrarXOREncoder() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo a cifrar: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCruda(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCifrada("xor_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave para el cifrado XOR: ";
    std::getline(std::cin, clave);

    if (clave.empty()) {
        std::cout << "La clave no puede estar vacia.\n";
        return;
    }

    std::string textoOriginal = Cesarin::leerArchivo(rutaEntrada);
    if (textoOriginal.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }

    XOREncoder xorEncoder;
    std::string textoCifrado = xorEncoder.encode(textoOriginal, clave);

    if (Cesarin::guardarArchivo(rutaSalida, textoCifrado)) {
        std::cout << "Archivo cifrado guardado correctamente en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo cifrado.\n";
    }
}

/**
 * @brief Descifra un archivo previamente cifrado con el algoritmo XOR.
 */
void Cifrador::descifrarXOR() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo cifrado: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCifrada(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCruda("recuperado_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave usada para el cifrado XOR: ";
    std::getline(std::cin, clave);

    if (clave.empty()) {
        std::cout << "La clave no puede estar vacía.\n";
        return;
    }

    std::string textoCifrado = Cesarin::leerArchivo(rutaEntrada);
    if (textoCifrado.empty()) {
        std::cout << "No se pudo leer el archivo cifrado o esta vacio.\n";
        return;
    }

    XOREncoder xorEncoder;
    std::string textoDescifrado = xorEncoder.encode(textoCifrado, clave); 

    if (Cesarin::guardarArchivo(rutaSalida, textoDescifrado)) {
        std::cout << "Archivo descifrado guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo descifrado.\n";
    }
}

/**
 * @brief Cifra un archivo usando el algoritmo Vigenère.
 */
void Cifrador::cifrarVigenere() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo a cifrar: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCruda(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCifrada("vigenere_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave para el cifrado Vigenere (solo letras): ";
    std::getline(std::cin, clave);

    if (clave.empty()) {
        std::cout << "La clave no puede estar vacia.\n";
        return;
    }

    std::string textoOriginal = Cesarin::leerArchivo(rutaEntrada);
    if (textoOriginal.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }
	// Crear el objeto Vigenère con la clave
    try {
        Vigenere vigenere(clave);
        std::string textoCifrado = vigenere.encode(textoOriginal);

        if (Cesarin::guardarArchivo(rutaSalida, textoCifrado)) {
            std::cout << "Archivo cifrado guardado en: " << rutaSalida << std::endl;
        }
        else {
            std::cout << "Error al guardar el archivo cifrado.\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error al crear el cifrador Vigenere: " << e.what() << std::endl;
    }
}

/**
 * @brief Descifra un archivo previamente cifrado con Vigenère.
 */
void Cifrador::descifrarVigenere() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo cifrado: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCifrada(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCruda("recuperado_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave usada para el cifrado Vigenere: ";
    std::getline(std::cin, clave);

    if (clave.empty()) {
        std::cout << "La clave no puede estar vacia.\n";
        return;
    }

    std::string textoCifrado = Cesarin::leerArchivo(rutaEntrada);
    if (textoCifrado.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }
	// Crear el objeto Vigenère con la clave
    try {
        Vigenere vigenere(clave);
        std::string textoDescifrado = vigenere.decode(textoCifrado);

        if (Cesarin::guardarArchivo(rutaSalida, textoDescifrado)) {
            std::cout << "Archivo descifrado guardado en: " << rutaSalida << std::endl;
        }
        else {
            std::cout << "Error al guardar el archivo descifrado.\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error al crear el descifrador Vigenere: " << e.what() << std::endl;
    }
}

/**
 * @brief Cifra un archivo convirtiendo el texto a su representación binaria (ASCII Binario).
 */
void Cifrador::cifrarAscii() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo a cifrar: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCruda(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCifrada("ascii_" + nombreArchivo);

    std::string textoOriginal = Cesarin::leerArchivo(rutaEntrada);
    if (textoOriginal.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }

    AsciiBinary ascii;
    std::string textoCifrado = ascii.stringToBinary(textoOriginal);

    if (Cesarin::guardarArchivo(rutaSalida, textoCifrado)) {
        std::cout << "Archivo cifrado (binario) guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo cifrado.\n";
    }
}

/**
 * @brief Descifra un archivo convirtiendo la representación binaria a texto ASCII.
 */
void Cifrador::descifrarAscii() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo cifrado: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCifrada(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCruda("recuperado_" + nombreArchivo);

    std::string textoCifrado = Cesarin::leerArchivo(rutaEntrada);
    if (textoCifrado.empty()) {
        std::cout << "No se pudo leer el archivo o está vacio.\n";
        return;
    }

    AsciiBinary ascii;
    std::string textoDescifrado = ascii.binaryToString(textoCifrado);

    if (Cesarin::guardarArchivo(rutaSalida, textoDescifrado)) {
        std::cout << "Archivo descifrado guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo descifrado.\n";
    }
}

/**
 * @brief Cifra un archivo usando el algoritmo DES.
 */
void Cifrador::cifrarDES() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo a cifrar: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCruda(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCifrada("des_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave de 8 caracteres (64 bits): ";
    std::getline(std::cin, clave);

    if (clave.size() != 8) {
        std::cout << "La clave debe tener exactamente 8 caracteres.\n";
        return;
    }

    std::string textoOriginal = Cesarin::leerArchivo(rutaEntrada);
    if (textoOriginal.empty()) {
        std::cout << "No se pudo leer el archivo o esta vacio.\n";
        return;
    }

    // Convertir la clave a bitset<64>
    std::bitset<64> claveBitset;
    for (int i = 0; i < 8; ++i) {
        claveBitset |= (std::bitset<64>(std::bitset<8>(clave[i]).to_ulong()) << (8 * (7 - i)));
    }

    // Crear el objeto DES con la clave
    DES des(claveBitset);

    std::string textoCifrado = "";
    for (size_t i = 0; i < textoOriginal.size(); i += 8) {
        std::string bloque = textoOriginal.substr(i, 8);
        if (bloque.size() < 8) {
            bloque.append(8 - bloque.size(), '\0');  // Rellenar con \0 si el bloque es menor a 8
        }

        std::bitset<64> bloqueBitset = des.stringToBitset64(bloque);
        std::bitset<64> bloqueCifrado = des.encode(bloqueBitset);
        textoCifrado += des.bitset64ToString(bloqueCifrado);  // Convertir el bitset a string
    }

    if (Cesarin::guardarArchivo(rutaSalida, textoCifrado)) {
        std::cout << "Archivo cifrado guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo cifrado.\n";
    }
}

/**
 * @brief Descifra un archivo previamente cifrado con DES.
 */
void Cifrador::descifrarDES() {
    std::string nombreArchivo;
    std::cout << "\nIngrese el nombre del archivo cifrado: ";
    std::getline(std::cin, nombreArchivo);

    std::string rutaEntrada = Cesarin::rutaCifrada(nombreArchivo);
    std::string rutaSalida = Cesarin::rutaCruda("recuperado_" + nombreArchivo);

    std::string clave;
    std::cout << "Ingrese la clave de 8 caracteres (64 bits): ";
    std::getline(std::cin, clave);

    if (clave.size() != 8) {
        std::cout << "La clave debe tener exactamente 8 caracteres.\n";
        return;
    }

    std::string textoCifrado = Cesarin::leerArchivo(rutaEntrada);
    if (textoCifrado.empty()) {
        std::cout << "No se pudo leer el archivo cifrado o esta vacio.\n";
        return;
    }

    // Convertir la clave a bitset<64>
    std::bitset<64> claveBitset;
    for (int i = 0; i < 8; ++i) {
        claveBitset |= (std::bitset<64>(std::bitset<8>(clave[i]).to_ulong()) << (8 * (7 - i)));
    }

    // Crear el objeto DES con la clave
    DES des(claveBitset);

    std::string textoDescifrado = "";
    for (size_t i = 0; i < textoCifrado.size(); i += 8) {
        std::string bloque = textoCifrado.substr(i, 8);

        std::bitset<64> bloqueBitset = des.stringToBitset64(bloque);
        std::bitset<64> bloqueDescifrado = des.decode(bloqueBitset);
        textoDescifrado += des.bitset64ToString(bloqueDescifrado);  // Convertir el bitset a string
    }

    if (Cesarin::guardarArchivo(rutaSalida, textoDescifrado)) {
        std::cout << "Archivo descifrado guardado en: " << rutaSalida << std::endl;
    }
    else {
        std::cout << "Error al guardar el archivo descifrado.\n";
    }
}