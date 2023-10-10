#include <iostream>

using namespace std;

// funcion que invierte un numero entero
int invertirNumero(int numero) {
    int invertido = 0;
    while (numero > 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }
    
    return invertido;
}

// usando la funcion para invertir
bool esCapicua_1(int numero) {
    return numero == invertirNumero(numero);
}

// sin usar la funcion para invertir
bool esCapicua_2(int numero) { // se implementa la funcion de inversion
    int invertido = 0, aux = numero;
    
    while (aux > 0) {
        invertido = invertido * 10 + aux % 10;
        aux /= 10;
    }
    
    return numero == invertido;
}

// sin usar la implementacion de invertir
bool esCapicua_3(int numero) {
    int divisor = 1; // divisor para obtener el multiple del numero
    // si 123, entonces divisor = 100
    // si 1234, entonces divisor = 1000

    // se obtiene el valor para el divisor
    while (numero / divisor >= 10) divisor *= 10;
    while (numero > 0) {
        int primero = numero / divisor; // obtener primer diigto
        int ultimo = numero % 10; // obtener ultimo digito

        // comprobar si son iguales
        if (primero != ultimo) return false;

        // se quitan los digitos primero y ultimo
        numero = (numero % divisor) / 10;
        // numero % divisor quita el primer digito
        // (numero % divisor) / 10 quita el ultimo digito
        divisor /= 100; // al haber quitado los dos digitos,
        // se divide entre 100 para quitar los dos ceros
    }

    return true;
}

int main() {
    int numero = 242;
    cout << "El numero " << numero << " invertido es: " << invertirNumero(numero) << endl;
    cout << endl;
    cout << "Metodos de si es capicúa: " << endl;
    cout << "1. 1 si es capicúa, 0 si no: " << esCapicua_1(numero) << endl;
    cout << "2. 1 si es capicúa, 0 si no: " << esCapicua_2(numero) << endl;
    cout << "3. 1 si es capicúa, 0 si no: " << esCapicua_3(numero) << endl;

    return 0;
}