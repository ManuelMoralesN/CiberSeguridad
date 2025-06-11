#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que implementa el cifrado y descifrado usando el algoritmo C�sar.
 *        Incluye m�todos para ataques de fuerza bruta y an�lisis de frecuencia.
 */
class CesarEncryption {
public:
    /**
     * @brief Constructor por defecto.
     */
    CesarEncryption() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~CesarEncryption() = default;

    /**
     * @brief Codifica un texto usando cifrado C�sar con el desplazamiento especificado.
     * @param texto Texto a codificar.
     * @param desplazamiento N�mero de posiciones para desplazar cada car�cter.
     * @return Texto codificado.
     * @note Soporta letras may�sculas, min�sculas y d�gitos del 0 al 9.
     */
    std::string encode(const std::string& texto, int desplazamiento) {
        std::string result = "";

        for (char c : texto) {
            if (c >= 'A' && c <= 'Z') {
                result += (char)(((c - 'A' + desplazamiento) % 26) + 'A');
            }
            else if (c >= 'a' && c <= 'z') {
                result += (char)(((c - 'a' + desplazamiento) % 26) + 'a');
            }
            else if (c >= '0' && c <= '9') {
                result += (char)(((c - '0' + desplazamiento) % 10) + '0');
            }
            else {
                result += c;
            }
        }

        return result;
    }

    /**
     * @brief Decodifica un texto cifrado con el algoritmo C�sar.
     * @param texto Texto cifrado.
     * @param desplazamiento Desplazamiento utilizado durante la codificaci�n.
     * @return Texto descifrado.
     */
    std::string decode(const std::string& texto, int desplazamiento) {
        return encode(texto, 26 - (desplazamiento % 26));
    }

    /**
     * @brief Realiza un ataque de fuerza bruta probando todas las claves posibles.
     * @param texto Texto cifrado.
     * @note Imprime por consola los posibles descifrados con cada clave de 0 a 25.
     */
    void bruteForceAttack(const std::string& texto) {
        std::cout << "\nIntentos de descifrado por fuerza bruta:\n";
        for (int clave = 0; clave < 26; clave++) {
            std::string intento = encode(texto, 26 - clave);
            std::cout << "Clave " << clave << ": " << intento << std::endl;
        }
    }

    /**
     * @brief Estima la clave m�s probable mediante an�lisis de frecuencia.
     * @param texto Texto cifrado.
     * @return Clave estimada.
     * @note Usa frecuencia de letras comunes en espa�ol y palabras clave para validar.
     */
    int evaluatePossibleKey(const std::string& texto) {
        int frecuencias[26] = { 0 };

        // Contar frecuencias de letras
        for (char c : texto) {
            if (c >= 'a' && c <= 'z') {
                frecuencias[c - 'a']++;
            }
            else if (c >= 'A' && c <= 'Z') {
                frecuencias[c - 'A']++;
            }
        }

        // Letras comunes en espa�ol (orden de frecuencia)
        const char letrasEsp[] = { 'e', 'a', 'o', 's', 'r', 'n', 'i', 'd', 'l', 'c' };

        // Buscar la letra m�s frecuente en el mensaje cifrado
        int indiceMax = 0;
        for (int i = 1; i < 26; ++i) {
            if (frecuencias[i] > frecuencias[indiceMax]) {
                indiceMax = i;
            }
        }

        // Probar varias suposiciones de mapeo
        int mejorClave = 0;
        int mejorPuntaje = -1;

        for (char letraRef : letrasEsp) {
            int clave = (indiceMax - (letraRef - 'a') + 26) % 26;
            int puntaje = 0;

            // Descifrar con esa clave
            std::string descifrado = encode(texto, 26 - clave);

            // Palabras comunes simples
            std::string comunes[] = { "el", "de", "la", "que", "en", "y", "los", "se" };

            for (std::string palabra : comunes) {
                if (descifrado.find(palabra) != std::string::npos) {
                    puntaje++;
                }
            }

            if (puntaje > mejorPuntaje) {
                mejorPuntaje = puntaje;
                mejorClave = clave;
            }
        }

        return mejorClave;
    }

private:

};
