// Extra: 25. Crear el programa para ingresar n números y al final,
//  mostrar de acuerdo a los siguientes rangos su correspondiente sumatoria:
// a) Números menores a 10
// b) Números entre 10 y 50
// c) Números mayores a 50

// Respuesta: 
// cpp
#include <iostream>

// la necesidad de la libreria de vectores en por listas dinamicas
#include <vector> 

using namespace std;

void menu() {
    cout << "1. Menores a 10" << endl;
    cout << "2. Entre 10 y 50" << endl;
    cout << "3. Mayores a 50" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion" << endl;
}

int main()
{
    cout << "Cantidad de numeros: " << endl;
    int n; cin >> n;
    vector<int> numeros;
    
    for (int i = 0; i < n; i++) {
        int auxiliar; cin >> auxiliar;
        numeros.push_back(auxiliar);
    }

    int opcion;

    do {
        menu();
        cin >> opcion;
        int resultado = 0;
        switch (opcion) {
        case 1:
            for (int i = 0; i < n; i++) {
                if (numeros[i] < 10) {
                    resultado += numeros[i];
                }
            }
            cout << "Resultado: " << resultado << endl;
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                if (numeros[i] >= 10 && numeros[i] < 50) {
                    resultado += numeros[i];
                }
            }
            cout << "Resultado: " << resultado << endl;
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                if (numeros[i] >= 50) {
                    resultado += numeros[i];
                }
            }
            cout << "Resultado: " << resultado << endl;
            break;
        case 4:
            cout << "Salir" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}
