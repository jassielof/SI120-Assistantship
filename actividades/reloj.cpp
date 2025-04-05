#include <iostream>

using namespace std;

void relojDigital(int HH, int MM, int SS) {
    SS--;

    while (true) {
        cout << "\x1b[2J\x1b[H";
        // limpiar pantalla mediante codigos de escape ANSI (ANSI ESCAPE CODE)
        // https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

        SS++; // ir aumentando los segundos

        if (SS >= 60) { // si llega a 60 o mas (si hay error)
            SS = 0; // reiniciar a 0
            MM++; // aumentar un minuto
            if (MM >= 60) { // si llega a 60...
                MM = 0; // reiniciar...
                HH++; // aumentar...
                if (HH >= 24) { // si...
                    HH = 0; // reiniciar...
                }
            }
        }
        cout << HH << ":" << MM << ":" << SS << flush;
        system("sleep 1"); // dormirse o esperar por un segundo
    }
}

int main() {
    relojDigital(17, 12, 0);

    return 0;
}
