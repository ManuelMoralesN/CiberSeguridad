#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que implementa funciones de codificación y decodificación XOR,
 *        así como ataques de fuerza bruta sobre textos cifrados.
 */
class XOREncoder {
public:
    /**
     * @brief Constructor por defecto.
     */
    XOREncoder() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~XOREncoder() = default;

    /**
     * @brief Codifica una cadena usando XOR con una clave proporcionada.
     * @param input Texto plano a codificar.
     * @param key Clave XOR usada para la codificación.
     * @return Cadena codificada.
     * @note La clave se repite si es más corta que el texto.
     */
    std::string encode(const std::string& input, const std::string& key) {
        std::string output = input;
        for (int i = 0; i < input.size(); i++) {
            output[i] = input[i] ^ key[i % key.size()];
        }
        return output;
    }

    /**
     * @brief Convierte una cadena en formato hexadecimal a un vector de bytes.
     * @param input Cadena en formato hexadecimal (con espacios entre valores).
     * @return Vector de bytes resultante.
     */
    std::vector<unsigned char> HexToBytes(const std::string& input) {
        std::vector<unsigned char> bytes;
        std::istringstream iss(input);
        std::string hexValue;

        while (iss >> hexValue) {
            if (hexValue.size() == 1) {
                hexValue = "0" + hexValue;
            }
            unsigned int byte;
            std::stringstream ss;
            ss << std::hex << hexValue;
            ss >> byte;
            bytes.push_back(static_cast<unsigned char>(byte));
        }
        return bytes;
    }

    /**
     * @brief Imprime una cadena como valores hexadecimales.
     * @param input Cadena de entrada.
     */
    void printHex(const std::string& input) {
        for (unsigned char c : input) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
        }
    }

    /**
     * @brief Verifica si una cadena contiene únicamente caracteres imprimibles o espacios.
     * @param data Cadena a evaluar.
     * @return true si todos los caracteres son imprimibles; false en caso contrario.
     */
    bool isValidText(const std::string& data) {
        return std::all_of(data.begin(), data.end(), [](unsigned char c) {
            return std::isprint(c) || std::isspace(c) || c == '\n' || c == ' ';
            });
    }

    /**
     * @brief Realiza un ataque de fuerza bruta con claves XOR de 1 byte.
     * @param cifrado Vector de bytes cifrados.
     * @note Muestra en consola los resultados con texto legible.
     */
    void bruteForce_1Byte(const std::vector<unsigned char>& cifrado) {
        for (int clave = 0; clave < 256; ++clave) {
            std::string result;

            for (unsigned char c : cifrado) {
                result += static_cast<unsigned char>(c ^ clave);
            }

            if (isValidText(result)) {
                std::cout << "=============================\n";
                std::cout << "Clave 1 byte  : '" << static_cast<char>(clave)
                    << "' (0x" << std::hex << std::setw(2) << std::setfill('0') << clave << ")\n";
                std::cout << "Texto posible : " << result << "\n";
            }
        }
    }

    /**
     * @brief Realiza un ataque de fuerza bruta con claves XOR de 2 bytes.
     * @param cifrado Vector de bytes cifrados.
     * @note Muestra en consola los resultados con texto legible.
     */
    void bruteForce_2Byte(const std::vector<unsigned char>& cifrado) {
        for (int b1 = 0; b1 < 256; ++b1) {
            for (int b2 = 0; b2 < 256; ++b2) {
                std::string result;
                unsigned char key[2] = { static_cast<unsigned char>(b1), static_cast<unsigned char>(b2) };

                for (int i = 0; i < cifrado.size(); i++) {
                    result += cifrado[i] ^ key[i % 2];
                }

                if (isValidText(result)) {
                    std::cout << "=============================\n";
                    std::cout << "Clave 2 bytes : '" << static_cast<char>(b1) << static_cast<char>(b2)
                        << "' (0x" << std::hex << std::setw(2) << std::setfill('0') << b1
                        << " 0x" << std::setw(2) << std::setfill('0') << b2 << ")\n";
                    std::cout << "Texto posible : " << result << "\n";
                }
            }
        }
    }

    /**
     * @brief Realiza un ataque de fuerza bruta usando claves comunes de un diccionario.
     * @param cifrado Vector de bytes cifrados.
     * @note Verifica si el texto resultante es legible y lo muestra por consola.
     */
    void bruteForceByDictionary(const std::vector<unsigned char>& cifrado) {
        std::vector<std::string> clavesComunes = {
            "clave", "admin", "1234", "root", "test", "abc", "hola", "user",
            "pass", "12345", "0000", "password", "default"
        };

        for (const auto& clave : clavesComunes) {
            std::string result;
            for (int i = 0; i < cifrado.size(); i++) {
                result += static_cast<unsigned char>(cifrado[i] ^ clave[i % clave.size()]);
            }
            if (isValidText(result)) {
                std::cout << "=============================\n";
                std::cout << "Clave de diccionario: '" << clave << "'\n";
                std::cout << "Texto posible : " << result << "\n";
            }
        }
    }

private:

};
