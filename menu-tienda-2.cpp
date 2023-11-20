/*
 * Diseñar un programa de modelo de menú para las reservas de un hotel que permita:
    * 1. Reservar una habitación.
    * 2. Cancelar una reserva.
    * 3. Mostrar las habitaciones disponibles.
    * 4. Mostrar las habitaciones ocupadas.
    * 5. Mostrar todas las habitaciones (más su estado).
    * 6. Mostrar los huéspedes de una habitación.
    * 7. Mostrar todos los huéspedes.
    * 8. Calcular el costo de reserva.
    * 9. Calcular el costo por estadía.
    * 10. Mostrar todos los huéspedes que se hayan hospedado por más de 3 días.
    * 11. Mostrar todos los huéspedes que se hayan hospedado por menos de 3 días.
    * 12. Mostrar todos los huéspedes que se hayan hospedado (incluyendo aquellos que no se encuentran hospedados).
    * 13. Mostrar una lista ordenada de los huéspedes por su apellido.
    * 14. Mostrar una lista ordenada de los huéspedes por su tiempo de estadía.
 *
 * Entonces:
 * Para las habitaciones:
 * Las habitaciones solo pueden ser reservadas, no hay atención en caja.
 * El hotel tiene una capacidad máxima de 100 habitaciones.
 * Cada habitación tiene una capacidad máxima de 10 huéspedes.
 * Las habitaciones tienen un estado, o libre o ocupado.
 * Todas las habitaciones tienen un mismo costo:
    * De reserva: El costo general de reserva vale 1000 pesos.
    * La habitación (cuarto, uso completo sin importar la cantidad de huéspedes): vale 750 pesos por día.
    * Por persona (huésped representante o acompañante): vale 250 pesos por día.
 * La factura del pago debe al momento de la reserva
 * 
 * Para la reserva:
 * La reserva no es acumulada, por tanto, no se debe hacer una lista de reservas.
 * La reserva entonces pide:
    * Nombre del huésped representante.
    * Apellido del huésped representante.
    * Fecha de ingreso, que debe ser mayor a la fecha actual.
    * Fecha de salida, que debe ser mayor a la fecha de ingreso.
    * Cantidad de días de estadía (solo enteros).
    * Cantidad de acompañantes (solo enteros).
 * En base a eso, la reserva, modifica las listas respectivas y devuelve el monto de pago.
 * 
 * Para los huéspedes:
 * Los huéspedes se dividen en dos partes, representante, y acompañantes.
    * El representante es quien se registra en la habitación.
    * Los acompañantes son los que se hospedan en la habitación.
 * El hotel solo registra los datos de los huéspedes representantes, los acompañantes no.
 * 
 * 
 * El hotel entonces tiene las siguientes listas:
    * Cantidad de habitaciones libres.
    * Cantidad de habitaciones ocupadas.
    * Cantidad de huéspedes (representantes).
    * Cantidad de acompañantes (por representante).
    * 
    * Lista de huéspedes (representantes).
    * Lista de acompañantes (por representante).
    * Lista de habitaciones (con su estado).
    * Lista de fechas de ingreso.
    * Lista de fechas de salida.
    * Lista de días de estadía.
    * Listas ordenadas de huéspedes por apellido.
**/
#include <iostream>

using namespace std;

int main() {
    const int capacidadHotel = 100;
    const int capacidadHabitacion = 10;
    
    // Lista para los huéspedes.

    int opcion = -1;

    while (opcion != 0) {
        cout
        << "0. Salir" << endl
        << "1. Reservar una habitación" << endl
        << "2. Cancelar una reserva" << endl
        << "3. Mostrar las habitaciones disponibles" << endl
        << endl;
        cout << "Ingrese una opción: "; cin >> opcion;
        system("clear");
    
        switch (opcion) {
            case 0:
                cout << "Saliendo..." << endl;
                break;
            case 1:
                cout << "Reservando una habitación..." << endl;
                break;
            case 2:
                cout << "Cancelando una reserva..." << endl;
                break;
            case 3:
                cout << "Mostrando las habitaciones disponibles..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
    }
    system("clear");

    return 0;
}