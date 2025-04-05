#include <iostream>
using namespace std;

void cargar(double a[], int t);
void mostrar(double a[], int t);
void invertir(double a[], double b[], int t);

int main() 
{
    int n;
    cout << "Ingrese el número de elementos en el vector: ";
    cin >> n;

    double arr[n];
    cargar(arr, n);

    // Crear un nuevo vector para almacenar la inversa
    double arrInvertido[n];

    // Invertir el vector y mostrarlo
    invertir(arr, arrInvertido, n);
    cout << "Vector Original:" << endl;
    mostrar(arr, n);
    cout << "Vector Invertido:" << endl;
    mostrar(arrInvertido, n);

    return 0;
}

void cargar(double a[], int t) 
{
    cout << "Ingrese los elementos del vector: ";
    for (int i = 0; i < t; i++) 
    {
        cin >> a[i];
    }
}

void mostrar(double a[], int t) 
{
    for (int i = 0; i < t; i++) 
    {
        cout << a[i] << endl;
    }
}

void invertir(double a[], double b[], int t) 
{
    // Invertir el vector 'a' en el vector 'b'
    for (int i = 0; i < t; i++) {
        b[i] = a[t - 1 - i];
    }
}

void invertirVectorUsandoMismoVector(double a[], int t) {
    // Invertir el vector 'a' en el mismo vector 'a'
    double aux;
    for (int i = 0; i < t / 2; i++) {
        aux = a[i]; // se almacena el primer elemento
        a[i] = a[t - 1 - i]; // se sobreescribe el primer elemento con el último
        a[t - 1 - i] = aux; // se sobreescribe el último elemento con el primero
    }
}

int main() {
    double a[10];
    int n;
    invertirVectorUsandoMismo(a, n);
    mostrar(a, n);
}