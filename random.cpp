#include <iostream>
#include <random> // Librería para generar números aleatorios, más versátil.
#include <cstdlib> // Librería para usar la función rand(), una alternativa a la librería random.
// cstdlib no acepta un rango con números negativos.

using namespace std;

int generarAleatorioConLimites(int bajo, int alto, string lib) {
    if (lib == "random") {
        // Explicando lo que hace esta parte del código:
        // https://en.cppreference.com/w/cpp/numeric/random
        random_device rd; // random_device:
        // Es un generador de números aleatorios que produce números aleatorios no deterministas.
        // rd se convierte en un objeto de la clase random_device.
        // Su valor vendría a ser un número aleatorio, un generador.
        mt19937 gen(rd()); // mt19937, Mersenne Twister, 19937 se refiere a la longitud del estado interno (sus bits).
        // En corto, es un motor para generar números aleatorios, un algoritmo.
        // Entre otros motores, tendríamos a minstd_rand, ranlux, knuth, default_random_engine.
        // gen(): vendría a ser el objeto de la clase mt19937.
        // Este objeto vendría a calcular el número aleatorio.
        // mt19937 <nombre de la variable>(<nombre de la variable aleatoria>());
        uniform_int_distribution<int> distr(bajo, alto); // por predeterminado produce un int
        // distr viene a ser el rango de números aleatorios que se pueden generar.
        return distr(gen); // distr(gen) devuelve un número aleatorio en el rango [bajo, alto].
    } else { // usando cstdlib
        return rand() % (alto - bajo) + alto;
    }
}

bool adivinarAleatorio(int numero, int aleatorio) {
    return numero == aleatorio;
}


int main() {
    int advinado, alto, bajo;
    cout << "Ingresar número para adivnar el aleatorio: "; cin >> advinado;
    cout << "Límite superior: "; cin >> alto;
    cout << "Límite inferior: "; cin >> bajo;
    string lib;
    cout << "Librería a usar (random o cstdlib): "; cin >> lib;
    int aleatorio = generarAleatorioConLimites(bajo, alto, lib);
    
    if (adivinarAleatorio(advinado, aleatorio)) {
        cout << "Acertaste" << endl;
    } else {
        cout << "Fallaste" << endl;
        cout << "El número aletorio era: " << aleatorio  << endl;
    }

    return 0;
}