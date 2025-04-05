// Calculo de series

#include <iostream>
#include <cmath> // para funcion de potencia `pow(base, exponente)`

using namespace std;

// S = x^1 + x^2 + x^3 + ... + x^n
// x y n son enteros
double serie_1(int n, int x) {
    double suma = 0;
    if (x == 0) return 0;
    else if (n == 0) return 1;
    else if (n == 1) return x;
    else {
        for (int i = 1; i <= n; i++) {
            suma += pow(x, i);
            // cout << x << "^" << i << " = " << pow(x, i) << endl;
        }
    }
    
    
    // cout << "S = " << suma << endl;
    return suma;
}


// S = x^1/1! + x^2/2! + x^3/3! + ... x^n/n!
// x y n son enteros

// funcion del factorial necesaria para la serie
double factorial(int n) {
    double factorial = 1;
    if (n < 0) return -1; // error de factorial
    else if (n == 0 || n == 1) return 1;
    for (int i = 1; i <= n; i++) factorial *= i;

    return factorial;
}

double serie_2(int n, int x) {
    double suma = 0;
    if (x == 0 || n == 0) return 0;
    for (int i = 1; i <= n; i++) suma += pow(x, i) / factorial(i);
    
    return suma;
}


// funcion principal
int main() {
    cout << "Resultado de la sumatoria tipo 1: " << endl;
    cout << serie_1(5, 5) << endl;
    
    cout << "Resultado de la sumatoria tipo 2: " << endl;
    cout << serie_2(10, 10) << endl;
    
    return 0;
}
