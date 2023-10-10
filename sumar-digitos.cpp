#include <iostream>

using namespace std;

int sumarDigitos(int n) {
    if (n < 0) { // si el numero es negativo
        return -1; // devolvemos -1 como prueba de error
    }

    int suma = 0;

    while (n > 0) { // mientras el numero sea mayor a 0
        suma += n % 10; // iremos sumando el sobrante
        n /= 10; // y dividiremos y sobreescribiremos el numero entre 10
    } // todo hasta que el numero sea 0 o menor

    return suma; // devolvemos el valor de la suma
}

int main() {
    int numero = 120;

    cout << "La suma de los digitos es: " << sumarDigitos(numero);

    return 0;
}