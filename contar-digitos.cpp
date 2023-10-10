#include <iostream>

using namespace std;

int contarDigitosPares(int n) {
    int contador = 0;

    while (n > 0) {
        if (n % 2 == 0) contador++;
        n /= 10;
    }
    
    return contador;
}

int contarDigitorsImpares(int n) {
    int contador = 0;

    while (n > 0) {
        if (n % 2 != 0) contador++;
        n /= 10;
    }
    
    return contador;
}

int contarDigitos(int n) {
    int contador = 0;

    while (n > 0) {
        contador++;
        n /= 10;
    }
    
    return contador;
}

int main() {
    int numero = 1234567890;
    cout << "Numero ejemplo: " << numero << endl;
    cout << "Cantidad de digitos: " << contarDigitos(numero) << endl;
    cout << "Cantidad de digitos pares: " << contarDigitosPares(numero) << endl;
    cout << "Cantidad de digitos impares: " << contarDigitorsImpares(numero) << endl;
    
    return 0;
}