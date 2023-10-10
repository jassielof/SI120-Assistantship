#include <iostream>

using namespace std;

float salarioBrutoTrabajador(float horasTrabajadas, float pagoPorHora) {
    return horasTrabajadas * pagoPorHora;
}

float salarioTrabajadorRCIVA(float salarioBrutoTrabajador, float rcIVA, float rcIVAlim) {
    if (salarioBrutoTrabajador > rcIVAlim) {
        return salarioBrutoTrabajador * rcIVA;
    }

    return 0;
}

float salarioNeto(float salarioBruto, float salarioRCIVA) {
    return salarioBruto - salarioRCIVA;
}

int main() {
    int cantTrabajadores = 200;
    float rcIVA = 0.13;
    float horasTrabajadas, pagoPorHora, salBruto, salTrabRCIVA, salNeto;
    float salarioLimRCIVA = 8272;
    string nombre;

    for (int i = 0; i < 200; i++) {
        cout << "Para dejar de calcular presione Ctrl + C" << endl;
        cout << endl;
        cout << "Nombre: "; cin >> nombre;
        cout << "Horas trabajadas: "; cin >> horasTrabajadas;
        cout << "Pago por hora: "; cin >> pagoPorHora;
        cout << endl;
        
        salBruto = salarioBrutoTrabajador(horasTrabajadas, pagoPorHora);
        salTrabRCIVA = salarioTrabajadorRCIVA(salBruto, rcIVA, salarioLimRCIVA);
        salNeto = salarioNeto(salBruto, salTrabRCIVA);

        cout << "Salario neto de " << nombre << ": " << salNeto << endl;
    }
    return 0;
}