#include "Prerequisites.h"
#include "Cifrador.h"

int main() {
    int opcion = 0;

    do {
        std::cout << "\n======= MANELIKENCRYPTION =======\n";
        std::cout << "\n======= MENU =======\n";
        std::cout << "1. Cifrar con Cesar\n";
        std::cout << "2. Descifrar con Cesar\n";
        std::cout << "3. Cifrar con XOR\n";
        std::cout << "4. Descifrar con XOR\n";
        std::cout << "5. Cifrar con Vigenere\n";
        std::cout << "6. Descifrar con Vigenere\n";
        std::cout << "7. Cifrar con ASCII Binario\n";
        std::cout << "8. Descifrar con ASCII Binario\n";
        std::cout << "9. Cifrar con DES\n";
        std::cout << "10. Descifrar con DES\n";
        std::cout << "0. Salir\n";
        std::cout << "Elige lo que quieres hacer: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:  Cifrador::cifrarCesar(); break;
        case 2:  Cifrador::descifrarCesar(); break;
        case 3:  Cifrador::cifrarXOREncoder(); break;
        case 4:  Cifrador::descifrarXOR(); break;
        case 5:  Cifrador::cifrarVigenere(); break;
        case 6:  Cifrador::descifrarVigenere(); break;
        case 7:  Cifrador::cifrarAscii(); break;
        case 8:  Cifrador::descifrarAscii(); break;
        case 9:  Cifrador::cifrarDES(); break;
        case 10: Cifrador::descifrarDES(); break;
        case 0:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opcion no valida. Intentalo de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
