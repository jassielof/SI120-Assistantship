#include <iostream>
using namespace std;

// Function declarations
void cargar(double a[], int t);
void mostrar(double a[], int t);
void invertir(double a[], double b[], int t);
void invertirVectorUsandoMismoVector(double a[], int t);

int main()
{
    int n;
    cout << "Ingrese el número de elementos en el vector: ";
    cin >> n;

    // Dynamically allocate memory for the arrays
    double* arr = new double[n];
    cargar(arr, n);

    // Create a new vector for storing the inverted array
    double* arrInvertido = new double[n];

    // Invert the vector and display it
    invertir(arr, arrInvertido, n);
    cout << "Vector Original:" << endl;
    mostrar(arr, n);
    cout << "Vector Invertido:" << endl;
    mostrar(arrInvertido, n);

    // Free dynamically allocated memory
    delete[] arr;
    delete[] arrInvertido;

    return 0;
}

// Function to load elements into the array
void cargar(double a[], int t)
{
    cout << "Ingrese los elementos del vector: ";
    for (int i = 0; i < t; i++)
    {
        cin >> a[i];
    }
}

// Function to display the elements of the array
void mostrar(double a[], int t)
{
    for (int i = 0; i < t; i++)
    {
        cout << a[i] << endl;
    }
}

// Function to invert one array into another
void invertir(double a[], double b[], int t)
{
    for (int i = 0; i < t; i++) {
        b[i] = a[t - 1 - i];
    }
}

// Function to invert an array in place
void invertirVectorUsandoMismoVector(double a[], int t)
{
    double aux;
    for (int i = 0; i < t / 2; i++) {
        aux = a[i]; // Store the first element
        a[i] = a[t - 1 - i]; // Overwrite the first element with the last
        a[t - 1 - i] = aux; // Overwrite the last element with the first
    }
}