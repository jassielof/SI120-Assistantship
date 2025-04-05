#include <iostream>

using namespace std;

// function to create array with undefined memory values and n size
int *createArrayN(int n) {
    int *array = new int[n];
    // return array = new int[n];
    return array;
}

void *modifyArray(int *array, int n) {
    for (int i{}; i < n; i++) {
        cout << i << "; ";
        // array[i] = i;
        cout << "val: "; cin >> array[i];
        cout << "array val: " << array[i] << endl;
    }
    cout << flush;
    return array;
}

int main() {
    // size as 10
    int n = 10;
    // call function to create the array with n size and store it
    int *newArray = createArrayN(n);
    for (int i{}; i < n; i++) {
        cout << "Val: " << *newArray << endl;
    }
    modifyArray(newArray, n);

    for (int i{}; i < n; i++) {
        cout << newArray[i] << endl;
    }

    return 0;
}