// Diseñar un programa que gestione el invventario de una pequeña tienda de abarrotes.
// El programa debe permitir, al usuario realizar las siguientes acciones (funciones):
// * Salir, con la opción 0.
// * Agregar un nuevo producto al inventario, incluyeno: nombre, precio, y cantidad en stock.
// * Actualizar la cantidad en stock de un producto ya existente.
// * Buscar un producto por su nombre y mostrar su información: nombre, precio, y cantidad en stock.
// * Mostrar una lista de todos los productos en el inventario.
// * Calcular el valor total el inventario mediante la fórmula: precio por cantidad en stock
//   (de todos los productos).

#include <iostream>

using namespace std;

int productosTotales = 0;

void agregarProducto(string nombreProducto[], double precioProducto[], int cantidadProducto[], int capacidadInventario) {
    if (productosTotales < capacidadInventario) {
        cout << "Ingrese el nombre del producto: "; cin >> nombreProducto[productosTotales];
        cout << "Ingrese el precio del producto: "; cin >> precioProducto[productosTotales];
        cout << "Ingrese la cantidad del producto: "; cin >> cantidadProducto[productosTotales];
        productosTotales++;
    } else {
        cout << "No hay espacio en el inventario." << endl;
    }
}

int buscarProducto(string nombreProducto[]) {
    string nombreProductoBuscado;
    cout << "Ingrese el nombre del producto a buscar: "; cin >> nombreProductoBuscado;
    for (int i = 0; i < productosTotales; i++) {
        if (nombreProducto[i] == nombreProductoBuscado) {
            return i;
        }
    }
    return -1;
}

void actualizarDetallesProducto(string nombreProducto[], double precioProducto[], int cantidadProducto[]) {
    int posicionProducto = buscarProducto(nombreProducto);
    if (posicionProducto != -1) {
        cout << "Ingrese el nuevo precio del producto: "; cin >> precioProducto[posicionProducto];
        cout << "Ingrese la nueva cantidad del producto: "; cin >> cantidadProducto[posicionProducto];
    } else {
        cout << "No se encontró el producto." << endl;
    }
}

void mostrarProductos(string nombreProducto[], double precioProducto[], int cantidadProducto[]) {
    for (int i = 0; i < productosTotales; i++) {
        cout << "Producto " << i + 1 << endl;
        cout << "Nombre: " << nombreProducto[i] << endl;
        cout << "Precio: " << precioProducto[i] << endl;
        cout << "Cantidad: " << cantidadProducto[i] << endl;
        cout << endl;
    }
}

double calcularValorTotalInventario(string nombreProducto[], double precioProducto[], int cantidadProducto[]) {
    double valorTotalInventario = 0;
    for (int i = 0; i < productosTotales; i++) {
        valorTotalInventario += precioProducto[i] * cantidadProducto[i];
    }
    return valorTotalInventario;
}

int main() {
    const int capacidadInventario = 100;
    cout << "La capacidad del inventario es: " << capacidadInventario << endl;
    int opcion = 0;
    int cantidadProductos = 0;
    string nombreProducto[capacidadInventario];
    double precioProducto[capacidadInventario];
    int cantidadProducto[capacidadInventario];
    double valorTotalInventario;
    int posicionProducto;

    do {
        cout << "0. Salir." << endl;
        cout << "1. Agregar producto al inventario." << endl;
        cout << "2. Actualizar detalles de un producto del inventario." << endl;
        cout << "3. Buscar un producto del inventario." << endl;
        cout << "4. Mostrar productos del inventario." << endl;
        cout << "5. Calcular valor total del inventario." << endl;
        cout << endl;

        cout << "Ingrese la opción: "; cin >> opcion;

        switch (opcion) {
            case 0:
                cout << "Saliendo..." << endl;
                break;
            case 1:
                cout << "Agregando producto al inventario..." << endl;
                agregarProducto(nombreProducto, precioProducto, cantidadProducto, capacidadInventario);
                break;
            case 2:
                cout << "Actualizando detalles de un producto del inventario..." << endl;
                actualizarDetallesProducto(nombreProducto, precioProducto, cantidadProducto);
                break;
            case 3:
                cout << "Buscando un producto del inventario..." << endl;
                posicionProducto = buscarProducto(nombreProducto);
                cout << "Producto encontrado en la posición: " << posicionProducto << endl;
                break;
            case 4:
                cout << "Mostrando productos del inventario..." << endl;
                mostrarProductos(nombreProducto, precioProducto, cantidadProducto);
                break;
            case 5:
                cout << "Calculando valor total del inventario..." << endl;
                valorTotalInventario = calcularValorTotalInventario(nombreProducto, precioProducto, cantidadProducto);
                cout << "El valor total del inventario es: " << valorTotalInventario << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }
    } while (opcion != 0);
    return 0;
}