/*
Desarrollar un programa que permita a los bibliotecarios *registrar* y *organizar* los libros en estantes virtuales *usando arreglos* para el almacenamiento de información de libros y *procedimientos para agregar, eliminar y buscar libros*.

Procedimientos principales:
* Agregar libro a la biblioteca, solo libros libres para prestar.
* Prestar el libro, si está prestado entonces pasa a ocupado. Solo libros libres.
* Devolver el libro, si está ocupado entonces pasa a libre. Solo libros ocupados.

* Buscar libro, cualquier libro.
* Eliminar libro, cualquier libro.

* Ver libros, todos con su estado.
* Ver libros libres.
* Ver libros prestados, marcados como ocupados.
* Ver libros vencidos.

* Ver libros más populares, los más usados. Cada libro prestado contiene un contador de veces prestadas.
* Ver menos populares, para eliminarlos.

Las listas que estarán relacionadas a un libro son:
* Código
* Autor
* Título
* Estado del libro: ocupado o libre o vencido.
* Fecha de edición.
* Cantidad de veces prestadas, para saber si un libro es popular o no.
*/

#include <iostream>

using namespace std;

void limpiarPantalla()
{
    string continuar;
    while (continuar != "ok") {
        cout << "Escriba 'ok', para continuar..." << endl;
        cin >> continuar;
    }
    system("clear");
}

void agregarLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int capacidadLibros)
{
    cout << "Agregar libro" << endl;
    for (int i = 0; i < capacidadLibros; i++)
    {
        if (
            // Comprobar que no existe un libro en tal posición
            autorLibro[i] == "" &&
            tituloLibro[i] == "" &&
            codigoLibro[i] == 0 &&
            fechaEdicionLibro[i] == "")
        {
            cout << "Autor: ";
            cin >> autorLibro[i];
            cout << "Título: ";
            cin >> tituloLibro[i];
            cout << "Código: ";
            cin >> codigoLibro[i];
            cout << "Fecha de edición: ";
            cin >> fechaEdicionLibro[i];
            estadoLibro[i] = "libre"; // Por predeterminado el libro está libre
            break;
        }
    }
}

void prestarLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros)
{
    cout << "Prestar libro" << endl;
    int codigo;
    cout << "Código: ";
    cin >> codigo;
    for (int i = 0; i < capacidadLibros; i++)
    {
        if (codigoLibro[i] == codigo)
        {
            if (estadoLibro[i] == "libre" || estadoLibro[i] == "vencido")
            {
                estadoLibro[i] = "ocupado";
                vecesPrestadasLibro[i]++;
                break;
            }
            else
            {
                cout << "El libro no está disponible" << endl;
            }
        }
    }
}

void devolverLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros)
{
    cout << "Devolver libro" << endl;
    int codigo;
    cout << "Código: ";
    cin >> codigo;
    for (int i = 0; i < capacidadLibros; i++)
    {
        if (codigoLibro[i] == codigo)
        {
            if (estadoLibro[i] == "ocupado")
            {
                estadoLibro[i] = "libre";
                break;
            }
            else
            {
                cout << "El libro no está prestado" << endl;
            }
        }
    }
}

void buscarLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros)
{
    cout << "Buscar libro" << endl;
    int codigo;
    cout << "Código: ";
    cin >> codigo;
    for (int i = 0; i < capacidadLibros; i++)
    {
        if (codigoLibro[i] == codigo)
        {
            cout << "Autor: " << autorLibro[i] << endl;
            cout << "Título: " << tituloLibro[i] << endl;
            cout << "Código: " << codigoLibro[i] << endl;
            cout << "Fecha de edición: " << fechaEdicionLibro[i] << endl;
            cout << "Veces prestadas: " << vecesPrestadasLibro[i] << endl;
            cout << "Estado del libro: " << estadoLibro[i] << endl;
            break;
        }
    }
}

void eliminarLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros,
    string librosEliminados[],
    int librosExistentes,
    int cantidadEliminados)
{
    cout << "Eliminar libro" << endl;
    int codigo;
    cout << "Código: ";
    cin >> codigo;
    for (int i = 0; i < capacidadLibros; i++)
    {
        if (codigoLibro[i] == codigo)
        {
            librosEliminados[cantidadEliminados] = codigoLibro[i];
            librosExistentes--;
            cantidadEliminados++;

            autorLibro[i] = "";
            tituloLibro[i] = "";
            codigoLibro[i] = 0;
            estadoLibro[i] = "";
            fechaEdicionLibro[i] = "";
            vecesPrestadasLibro[i] = 0;
            break;
        }
    }
}

void verLibros(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros,
    int librosExistentes)
{
    cout << "Libros\n"
         << endl;

    for (int i = 0; i < capacidadLibros; i++)
    {
        if (
            autorLibro[i] == "" &&
            tituloLibro[i] == "" &&
            fechaEdicionLibro[i] == "")
            continue;
        cout << "\t Autor: \t" << autorLibro[i] << endl;
        cout << "\t Título: \t" << tituloLibro[i] << endl;
        cout << "\t Código: \t" << codigoLibro[i] << endl;
        cout << "\t Estado: \t" << estadoLibro[i] << endl;
        cout << "\t Fecha: \t" << fechaEdicionLibro[i] << endl;
        cout << "\t # Prestadas: \t" << vecesPrestadasLibro[i] << endl;
    }
}

void verLibrosLibres(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros,
    int librosExistentes)
{
    cout << "Libros libres\n"
         << endl;

    for (int i = 0; i < capacidadLibros; i++)
    {
        if (
            autorLibro[i] == "" &&
            tituloLibro[i] == "" &&
            fechaEdicionLibro[i] == "")
            continue;
        if (estadoLibro[i] == "libre")
        {
            cout << "\t Autor: \t" << autorLibro[i] << endl;
            cout << "\t Título: \t" << tituloLibro[i] << endl;
            cout << "\t Código: \t" << codigoLibro[i] << endl;
            cout << "\t Estado: \t" << estadoLibro[i] << endl;
            cout << "\t Fecha: \t" << fechaEdicionLibro[i] << endl;
            cout << "\t # Prestadas: \t" << vecesPrestadasLibro[i] << endl;
        }
    }
}

void verLibrosPrestados(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros,
    int librosExistentes)
{
    cout << "Libros prestados\n"
         << endl;

    for (int i = 0; i < capacidadLibros; i++)
    {
        if (
            autorLibro[i] == "" &&
            tituloLibro[i] == "" &&
            fechaEdicionLibro[i] == "")
            continue;
        if (estadoLibro[i] == "ocupado")
        {
            cout << "\t Autor: \t" << autorLibro[i] << endl;
            cout << "\t Título: \t" << tituloLibro[i] << endl;
            cout << "\t Código: \t" << codigoLibro[i] << endl;
            cout << "\t Estado: \t" << estadoLibro[i] << endl;
            cout << "\t Fecha: \t" << fechaEdicionLibro[i] << endl;
            cout << "\t # Prestadas: \t" << vecesPrestadasLibro[i] << endl;
        }
    }
}

void verLibrosVencidos(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string estadoLibro[],
    string fechaEdicionLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros,
    int librosExistentes)
{
    cout << "Libros vencidos\n"
         << endl;

    for (int i = 0; i < capacidadLibros; i++)
    {
        if (
            autorLibro[i] == "" &&
            tituloLibro[i] == "" &&
            fechaEdicionLibro[i] == "")
            continue;
        if (estadoLibro[i] == "vencido")
        {
            cout << "\t Autor: \t" << autorLibro[i] << endl;
            cout << "\t Título: \t" << tituloLibro[i] << endl;
            cout << "\t Código: \t" << codigoLibro[i] << endl;
            cout << "\t Estado: \t" << estadoLibro[i] << endl;
            cout << "\t Fecha: \t" << fechaEdicionLibro[i] << endl;
            cout << "\t # Prestadas: \t" << vecesPrestadasLibro[i] << endl;
        }
    }
}

void clasificarPopulares(
    int vecesPrestadasLibro[],
    int capacidadLibros,
    int indiceLibrosPopulares[])
{
    for (int i = 0; i < capacidadLibros; i++)
    {
        indiceLibrosPopulares[i] = i;
    }

    for (int i = 0; i < capacidadLibros; i++)
    {
        for (int j = i + 1; j < capacidadLibros; j++)
        {
            if (vecesPrestadasLibro[indiceLibrosPopulares[j]] > vecesPrestadasLibro[indiceLibrosPopulares[i]])
            {
                int aux = indiceLibrosPopulares[i];
                indiceLibrosPopulares[i] = indiceLibrosPopulares[j];
                indiceLibrosPopulares[j] = aux;
            }
        }
    }
}

void mostrarPopulares(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    int vecesPrestadasLibro[],
    int indiceLibrosPopulares[],
    int librosExistentes)
{
    cout << "Libros populares\n"
         << endl;

    clasificarPopulares(
        vecesPrestadasLibro,
        librosExistentes,
        indiceLibrosPopulares);

    for (int i = 0; i < librosExistentes; i++)
    {
        int indice = indiceLibrosPopulares[i];
        cout << "\t Autor: \t" << autorLibro[indice] << endl;
        cout << "\t Título: \t" << tituloLibro[indice] << endl;
        cout << "\t Código: \t" << codigoLibro[indice] << endl;
        cout << "\t # Prestadas: \t" << vecesPrestadasLibro[indice] << endl;
    }
}

void vencerLibro(
    string autorLibro[],
    string tituloLibro[],
    int codigoLibro[],
    string fechaEdicionLibro[],
    int librosExistentes,
    string estadoLibro[],
    int vecesPrestadasLibro[],
    int capacidadLibros)
{
    buscarLibro(
        autorLibro,
        tituloLibro,
        codigoLibro,
        estadoLibro,
        fechaEdicionLibro,
        vecesPrestadasLibro,
        capacidadLibros);
    
    cout << "Fecha para vencer el libro: ";
    string fechaVencimiento;
    cin >> fechaVencimiento;
    cout << "Código del libro: ";
    int codigo;
    cin >> codigo;

    for (int i = 0; i < capacidadLibros; i++)
    {
        cout << "codigo: " << codigoLibro[i] << endl;
        cout << "fecha: " << fechaEdicionLibro[i] << endl;
        cout << "codigo input: " << codigo << endl;
        cout << "fecha input: " << fechaVencimiento << endl;
        if (
            fechaEdicionLibro[i] <= fechaVencimiento &&
            codigoLibro[i] == codigo)
        {
            estadoLibro[i] = "vencido";
            cout << "Libro vencido" << endl;
        }
    }
}

int main()
{
    const int capacidadLibros = 100;
    string autorLibro[capacidadLibros];
    string tituloLibro[capacidadLibros];
    int codigoLibro[capacidadLibros];
    string estadoLibro[capacidadLibros];
    string fechaEdicionLibro[capacidadLibros];
    int vecesPrestadasLibro[capacidadLibros];
    string librosEliminados[capacidadLibros];
    int librosExistentes = 0;
    int cantidadEliminados = 0;
    int indiceLibrosPopulares[capacidadLibros];

    cout << "Biblioteca Virtual\n"
         << endl;

    int opcion = 0;
    do
    {
        cout << "\t 0. Salir" << endl;
        cout << "\t 1. Agregar libro" << endl;
        cout << "\t 2. Prestar libro" << endl;
        cout << "\t 3. Devolver libro" << endl;
        cout << "\t 4. Buscar libro" << endl;
        cout << "\t 5. Eliminar libro" << endl;
        cout << "\t 6. Ver libros" << endl;
        cout << "\t 7. Ver libros libres" << endl;
        cout << "\t 8. Ver libros prestados" << endl;
        cout << "\t 9. Ver libros vencidos" << endl;
        cout << "\t10. Ver libros más populares" << endl;
        cout << "\t11. Vencer libro" << endl;

        cout << "Opción: ";
        cin >> opcion;

        if (opcion < 0 || opcion > 11)
            cout << "Opción inválida" << endl;
        else if (opcion == 1)
        {
            agregarLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                capacidadLibros);
            librosExistentes++;
        }
        else if (opcion == 2)
        {
            prestarLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros);
        }
        else if (opcion == 3)
        {
            devolverLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros);
        }
        else if (opcion == 4)
        {
            buscarLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros);
        }
        else if (opcion == 5)
        {
            eliminarLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros,
                librosEliminados,
                librosExistentes,
                cantidadEliminados);
        }
        else if (opcion == 6)
        {
            verLibros(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros,
                librosExistentes);
        }
        else if (opcion == 7)
        {
            verLibrosLibres(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros,
                librosExistentes);
        }
        else if (opcion == 8)
        {
            verLibrosPrestados(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros,
                librosExistentes);
        }
        else if (opcion == 9)
        {
            verLibrosVencidos(
                autorLibro,
                tituloLibro,
                codigoLibro,
                estadoLibro,
                fechaEdicionLibro,
                vecesPrestadasLibro,
                capacidadLibros,
                librosExistentes);
        }
        else if (opcion == 10)
        {
            cout << "Libros existentes: " << librosExistentes << endl;
            mostrarPopulares(
                autorLibro,
                tituloLibro,
                codigoLibro,
                vecesPrestadasLibro,
                indiceLibrosPopulares,
                librosExistentes);
        }
        else if (opcion == 11)
        {
            vencerLibro(
                autorLibro,
                tituloLibro,
                codigoLibro,
                fechaEdicionLibro,
                librosExistentes,
                estadoLibro,
                vecesPrestadasLibro,
                capacidadLibros);
        }
        limpiarPantalla();
    } while (opcion != 0);

    return 0;
}