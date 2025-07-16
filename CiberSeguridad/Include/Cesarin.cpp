#include "Cesarin.h"

std::string Cesarin::leerArchivo(const std::string& ruta) {
    std::ifstream archivo(ruta);
	// Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        return "";
    }

	std::stringstream buffer;     // Crea un buffer de stringstream para almacenar el contenido
	buffer << archivo.rdbuf();  // Lee todo el contenido del archivo en el buffer
	archivo.close(); // Cierra el archivo
	return buffer.str(); // Devuelve el contenido del buffer como un string
}

bool Cesarin::guardarArchivo(const std::string& ruta, const std::string& contenido) {
    std::ofstream archivo(ruta);
	// Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        return false;
    }

	archivo << contenido; // Escribe el contenido en el archivo
	archivo.close(); // Cierra el archivo
    return true;
}

std::string Cesarin::rutaCruda(const std::string& nombreArchivo) {
    return "Datos/DatosCrudos/" + nombreArchivo;
}

std::string Cesarin::rutaCifrada(const std::string& nombreArchivo) {
    return "Datos/DatosCif/" + nombreArchivo;
}
