#include <iostream>
#include <vector>

using namespace std;

// En este problema se busca crear un vector de n elementos, donde n es un valor dado por el usuario.
// Luego el vector debe ser llenado con valores dados por el usuario.
// Para así, crear funciones en base ese vector.

// Tenemos dos alternativas, crear un vector con una lista de c++ (int vector[]), o usar la librería de vector (que es más recomendable).


// Estas funciones están bien, pero podríamos agregar la creación del vector, fuera de la función para ingresar los datos.
// Para poder crear 
// void Ingresar_datos(int vector[],int n);
// int Buscar(int vector [], int n, int x1);
// int Mayor(int vector[],int n, int &indice);
// void Mostrar(int vector[],int &n);

int main(int argc, char** argv) {
	// int n = 0;
	// int vector[n]; // n no puede ser usado como el valor de un arreglo, ya que no es constante, puede ser cambiado.
    // Para evitar esto, se crea una constante.
    // const int n = 0; // n no puede ser cambiado.
    // pero aquí no funcionaría ya que el arreglo debe tener más de 0 elementos.
    // const int n = 10; // aquí sí funcionaría.
    // const int n; // no funcionaría ya que siempre se debe inicializar una constante definida.
    // tendríamos tales alternativas
    // Usando punteros:
    int n;
    cout << "Dar el tamaño del vector: "; cin >> n;
    int *vector = new int[n]; // new int[n] crea un arreglo de n elementos.
	int x1;
	int indi=0;
	Ingresar_datos(vector, n);
    cout<<"muestra los datos del vector"<<endl;
	Mostrar(vector,n);
    int x=Mayor(vector,n,indi);
    cout<<"numero mayor: "<<x<<"  indice: "<<indi<<endl;
    cout<<"Dar el valor x: ";cin>>x1;
    int y= Buscar(vector,n, x1);
    if (y==-1) { cout<<"No se encontro x.";}
    else { cout<<"Encontro el valor x "<<x1<<" en la posicion "<<y<<endl;}
	return 0;
}

// void Ingresar_datos(int vector[],int &n) {
// int &n: esta referenciando a n, por 'referenciar' a n, se quire decir que estamos usando la misma variable n, por más que esté fuera de la función, cada cambio que le suceda a la variable n dentro la función, se verá reflejado en la variable n fuera de la función.
// Lo cual no queremos, ya que no necesitamos que n sea cambiado, es simplemente el tamaño del vector
void Ingresar_datos(int vector[], int n) {
//   cout<<" dar el tamaño del vector: ";
//   cin>>*n;
// Tal hubiese sido el caso, de intentar usando referencia, no se podría ya que el valor de n dentro del vector ya no puede ser cambiado, es un vector estático.
 int i=0;
  while (i<n)
  {
     cout<<"  vector["<<i<<"]: ";
	 cin>>vector[i];
	 cout<<"valor de i "<<i<<endl;
	 cout<<"valor de n "<<n<<endl;
	 i++;
  }
}

int Mayor(int vector[],int n, int &indice) {
int x;
x=vector[0];
int i=1;
  while(i<n)
  {
     if (vector[i]>x) {

     				        x=vector[i];
							indice=i;
                       }
	 i++;
  };

  return x;
};
void Mostrar(int vector[],int &n)
 {
  for(int i=0;i<n;i++)
  {
     cout<<"  vector["<<i<<"]: "<<vector[i]<<endl;
  }
}
int Buscar(int vector [], int n, int x1)
{
		bool encontro=false;
			int indice=-1;

	for (int i=0; ((i<n) && (encontro==false)); i++)
	{


		if (vector [i]==x1)
		{
			indice=i;
			encontro=true;
	    }

    }
  	return indice;
}

int Buscar(int vector[], int n, int x1);
void Ingresar_datos(int vector[], int &n);
int Mayor(int vector[], int n, int &indice);
void Mostrar(int vector[], int &n);

int main(int argc, char** argv) {
    int n;
    cout << "Dar el tamaño del vector: ";
    cin >> n;
    int vector[n];
    int x1;
    int indi = 0;
    Ingresar_datos(vector, n);
    cout << "Muestra los datos del vector" << endl;
    Mostrar(vector, n);
    int x = Mayor(vector, n, indi);
    cout << "Número mayor: " << x << "  Índice: " << indi << endl;
    cout << "Dar el valor x: ";
    cin >> x1;
    int y = Buscar(vector, n, x1);
    if (y == -1) {
        cout << "No se encontró x." << endl;
    } else {
        cout << "Se encontró el valor x " << x1 << " en la posición " << y << endl;
    }
    return 0;
}

void Ingresar_datos(int vector[], int &n) {
    int i = 0;
    while (i < n) {
        cout << "  vector[" << i << "]: ";
        cin >> vector[i];
        i++;
    }
}

int Mayor(int vector[], int n, int &indice) {
    int x = vector[0];
    int i = 1;
    while (i < n) {
        if (vector[i] > x) {
            x = vector[i];
            indice = i;
        }
        i++;
    }
    return x;
}

void Mostrar(int vector[], int &n) {
    for (int i = 0; i < n; i++) {
        cout << "  vector[" << i << "]: " << vector[i] << endl;
    }
}

int Buscar(int vector[], int n, int x1) {
    for (int i = 0; i < n; i++) {
        if (vector[i] == x1) {
            return i;
        }
    }
    return -1;
}