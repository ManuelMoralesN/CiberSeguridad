#pragma once
#include "Prerequisites.h"

/**
 * @brief Clase utilitaria para manejo de archivos y rutas.
 */
class Cesarin {
public:
    /**
     * @brief Lee el contenido de un archivo de texto.
     * @param ruta Ruta completa del archivo.
     * @return Contenido del archivo como string. Si falla, devuelve cadena vacía.
     */
    static std::string leerArchivo(const std::string& ruta);

    /**
     * @brief Guarda un texto en un archivo.
     * @param ruta Ruta completa del archivo a guardar.
     * @param contenido Contenido que se va a escribir.
     * @return true si el archivo se guardó correctamente, false si falló.
     */
    static bool guardarArchivo(const std::string& ruta, const std::string& contenido);

    /**
     * @brief Genera la ruta completa de un archivo en DatosCrudos.
     * @param nombreArchivo Nombre del archivo (ej. ejemplo.txt).
     * @return Ruta con prefijo bin/DatosCrudos/
     */
    static std::string rutaCruda(const std::string& nombreArchivo);

    /**
     * @brief Genera la ruta completa de un archivo en DatosCif.
     * @param nombreArchivo Nombre del archivo (ej. cesar_ejemplo.txt).
     * @return Ruta con prefijo bin/DatosCif/
     */
    static std::string rutaCifrada(const std::string& nombreArchivo);
};
