#include <iostream>
#include <vector>

using namespace std;

// Function declarations
void Ingresar_datos(int vector[], int n);
int Mayor(int vector[], int n, int &indice);
void Mostrar(int vector[], int n);
int Buscar(int vector[], int n, int x1);

int main() {
    int n;
    cout << "Dar el tamaño del vector: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *vector = new int[n];

    int x1;
    int indi = 0;

    // Input data into the vector
    Ingresar_datos(vector, n);

    // Display the vector
    cout << "Muestra los datos del vector:" << endl;
    Mostrar(vector, n);

    // Find the largest number and its index
    int x = Mayor(vector, n, indi);
    cout << "Número mayor: " << x << "  Índice: " << indi << endl;

    // Search for a specific value in the vector
    cout << "Dar el valor x: ";
    cin >> x1;
    int y = Buscar(vector, n, x1);
    if (y == -1) {
        cout << "No se encontró x." << endl;
    } else {
        cout << "Se encontró el valor x " << x1 << " en la posición " << y << endl;
    }

    // Free dynamically allocated memory
    delete[] vector;

    return 0;
}

// Function to input data into the vector
void Ingresar_datos(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  vector[" << i << "]: ";
        cin >> vector[i];
    }
}

// Function to find the largest number in the vector and its index
int Mayor(int vector[], int n, int &indice) {
    int x = vector[0];
    indice = 0;
    for (int i = 1; i < n; i++) {
        if (vector[i] > x) {
            x = vector[i];
            indice = i;
        }
    }
    return x;
}

// Function to display the vector
void Mostrar(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "  vector[" << i << "]: " << vector[i] << endl;
    }
}

// Function to search for a value in the vector
int Buscar(int vector[], int n, int x1) {
    for (int i = 0; i < n; i++) {
        if (vector[i] == x1) {
            return i;
        }
    }
    return -1;
}