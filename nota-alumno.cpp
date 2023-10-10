#include <iostream>

using namespace std;

float notaAlumno(float parcial_1,
                 float parcial_2,
                 float parcial_3,
                 float examenFinal,
                 float proyectoFinal) {
    return (parcial_1 * 0.40/3) +
           (parcial_2 * 0.40/3) +
           (parcial_3 * 0.40/3) +
           (examenFinal * 0.40) +
           (proyectoFinal * 0.20);
}

int main() {
    int cantAlumnos = 40;
    float parcial_1, parcial_2, parcial_3, examenFinal, proyectoFinal;
    
    for (int i = 0; i < 40; i++) {
        cout << "Para dejar de calcular presione Ctrl + C" << endl;
        cout << "Parcial 1: "; cin >> parcial_1;
        cout << "Parcial 2: "; cin >> parcial_2;
        cout << "Parcial 3: "; cin >> parcial_3;
        cout << "Examen final: "; cin >> examenFinal;
        cout << "Proyecto final: "; cin >> proyectoFinal;
        cout << endl;
        cout << "Nota final: " << notaAlumno(parcial_1, parcial_2, parcial_3, examenFinal, proyectoFinal) << endl;
        cout << endl;
    }

    return 0;
}