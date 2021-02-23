#include <iostream>
#include "DynSortImp.h"
#include "staticlb.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;

void GenerateArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 200 - 101;
    }
}

int* CopyArray(int* array, int size) {
    int* copy = new int[size];
    for (int i = 0; i < size; ++i) {
        copy[i] = array[i];
    }
    return copy;
}

void OutputArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << std::endl;
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* array = new int[n];
    GenerateArray(array, n);
    int* arrayForStaticLib = CopyArray(array, n);
    int* arrayForImplicitDll = CopyArray(array, n);

    cout << "Input array:\n";
    OutputArray(array, n);

    Sort(arrayForStaticLib, n);
    SortDyn(arrayForImplicitDll, n);

    HINSTANCE hDLL = LoadLibrary(TEXT(".\\..\\Dynamic_explicit\\Debug\\Dexplicit.dll"));
    void (*sortAlgo)(int*, int);
    sortAlgo = (void(*)(int*, int))(GetProcAddress(hDLL, "Sort"));
    sortAlgo(array, n);

    cout << "Result of sort algo from static lib:\n";
    OutputArray(arrayForStaticLib, n);
    cout << "Result of sort algo from dynamic lib with implicit link:\n";
    OutputArray(arrayForImplicitDll, n);
    cout << "Result of sort algo from dynamic lib with explicit link:\n";
    OutputArray(array, n);
    cout << "Put enter to exit: ";
    getchar();
    getchar();
    delete[] arrayForImplicitDll;
    delete[] arrayForStaticLib;
    delete[] array;
    return 0;
}

