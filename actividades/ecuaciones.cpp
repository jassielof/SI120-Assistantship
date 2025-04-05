#include <iostream>

using namespace std;

// tipo linear Ax + B = C
float ecuacionLineal(float A, float B, float C) {
    return (C - B) / A;
}

// sistema de ecuaciones
// tipo:
// Ax + By = C
// Dx + Ey = F
float sistemaEcuaciones(
    float A,
    float B,
    float C,
    float D,
    float E,
    float F
) {
    // Calculate the determinant
    float determinant = A * E - B * D;

    // Check if the determinant is zero (no unique solution)
    if (determinant == 0) {
        cout << "The system of equations has no unique solution." << endl;
        return -1; // Return an error code
    }

    // Calculate x and y
    float x = (C * E - B * F) / determinant;
    float y = (A * F - C * D) / determinant;

    // Print the solution
    cout << "Solution: x = " << x << ", y = " << y << endl;

    return 0; // Indicate success
}

int main() {
    // Example usage
    float A = 2, B = 3, C = 8;
    float D = 1, E = -2, F = -3;

    sistemaEcuaciones(A, B, C, D, E, F);

    return 0;
}