#include <iostream>
#include <cmath>

using namespace std;

float areaEsfera(float diametro) {
    return (4 * M_PI * pow(diametro / 2, 2));
}

float volumenEsfera(float diametro) {
    return (4 / 3 * M_PI * pow(diametro / 2, 3));
}

float circunferenciaEsfera(float diametro) {
    return (M_PI * diametro);
}

int main() {
    for (int i = 0; i < 500; i++) {
        cout << "Para dejar de calcular presione Ctrl + C" << endl;
        float diametro;
        cout << "Diametro: "; cin >> diametro;
        cout << "Area: " << areaEsfera(diametro) << endl;
        cout << "Volumen: " << volumenEsfera(diametro) << endl;
        cout << "Circunferencia: " << circunferenciaEsfera(diametro) << endl;
    }

    return 0;
}