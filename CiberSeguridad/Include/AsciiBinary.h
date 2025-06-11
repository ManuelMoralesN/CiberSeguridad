#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase que proporciona funciones para convertir entre texto ASCII y su representación binaria.
 */
class AsciiBinary {
public:
    /**
     * @brief Constructor por defecto.
     */
    AsciiBinary() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~AsciiBinary() = default;

    /**
     * @brief Convierte un carácter ASCII a su representación binaria de 8 bits.
     * @param c Carácter a convertir.
     * @return Cadena de 8 caracteres '0' o '1' representando el valor binario.
     */
    std::string bitset(char c) {
        std::string result(8, '0');
        int value = static_cast<unsigned char>(c);
        for (int i = 7; i >= 0; --i) {
            result[i] = (value % 2) + '0';
            value /= 2;
        }
        return result;
    }

    /**
     * @brief Convierte una cadena ASCII en su representación binaria separada por espacios.
     * @param input Cadena original.
     * @return Representación binaria con 8 bits por carácter separados por espacios.
     */
    std::string stringToBinary(const std::string& input) {
        std::ostringstream oss;
        for (char c : input) {
            oss << bitset(c) << " ";
        }

        std::string output = oss.str();
        if (!output.empty()) {
            output.pop_back(); // Eliminar espacio final
        }

        return output;
    }

    /**
     * @brief Convierte una cadena de 8 bits en un carácter ASCII.
     * @param binary Cadena binaria de 8 caracteres ('0' o '1').
     * @return Carácter correspondiente al valor binario.
     */
    char binaryToChar(const std::string& binary) {
        int value = 0;
        for (char bit : binary) {
            value = value * 2 + (bit - '0');
        }

        return static_cast<char>(value);
    }

    /**
     * @brief Convierte una cadena binaria completa separada por espacios a texto ASCII.
     * @param binaryInput Cadena binaria con grupos de 8 bits separados por espacios.
     * @return Cadena ASCII resultante.
     */
    std::string binaryToString(const std::string& binaryInput) {
        std::istringstream iss(binaryInput);
        std::string result;
        std::string binary;

        while (iss >> binary) {
            result += binaryToChar(binary);
        }
        return result;
    }

private:

};
