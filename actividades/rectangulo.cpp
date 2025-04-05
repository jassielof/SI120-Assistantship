#include <iostream>

using namespace std;

float areaRectangulo(float base, float altura) {
    return base * altura;
}

// funcion basica
int main() {
    float base, altura;
    cout << "Ingrese la base del rectangulo: "; cin >> base;
    cout << "Ingrese la altura del rectangulo: "; cin >> altura;
    
    cout << "El area del rectangulo es: " << areaRectangulo(base, altura) << endl;
    
    return 0;
}

// funcion con while loop
/*
int main() {
    int opcion;
    float base, altura;
    do {
        cout << "Ingrese la base del rectangulo: "; cin >> base;
        cout << "Ingrese la altura del rectangulo: "; cin >> altura;
        cout << "El area del rectangulo es: " << areaRectangulo(base, altura) << endl;
        cout << "Desea calcular otra area? (1 = si, 0 = no): "; cin >> opcion;
    } while (opcion == 1);

    return 0;
}
*/

// funcion con for loop
/*
int main() {
    int cantidad;
    cout << "Ingrese la cantidad de rectangulos que desea calcular: "; cin >> cantidad;
    float base, altura;
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la base del rectangulo: "; cin >> base;
        cout << "Ingrese la altura del rectangulo: "; cin >> altura;
        cout << "El area del rectangulo es: " << areaRectangulo(base, altura) << endl;
    }
    
    return 0;
}
*/