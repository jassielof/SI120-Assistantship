#include <iostream>

using namespace std;

bool esBase_n(int numero, int base) {
    if (base < 2 || base > 10) return false; // limite de la base
    if (numero == 0) return true;
    else if (numero < 0) numero *= -1; // Si el número es negativo, lo volvemos positivo


    while (numero > 0) {
        if (numero % base >= base) return false;
        numero /= base;
    }

    return true;
}

int main() {
    int numero = 8;
    int base = 8;

    cout << "¿El número " << numero << " está en base " << base << " ? (1 = verdad, 0 = falso):" << endl;
    cout << esBase_n(numero, base) << endl;

    return 0, base;
}
