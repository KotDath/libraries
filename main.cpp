#include <iostream>
#include "DynSortImp.h"
#include "staticlb.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>

using std::cin;  //!!! Не нужно использовать using в глоьальном пространстве. Лучше везде писать явно std::
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
    cout << "Result of sort algo from static lib:\n";
    OutputArray(arrayForStaticLib, n);
    cout << "Result of sort algo from dynamic lib with implicit link:\n";
    OutputArray(arrayForImplicitDll, n);
    
    HINSTANCE SortLib = LoadLibrary(TEXT(".\\..\\Dynamic_explicit\\Debug\\Dexplicit.dll"));
    if (SortLib != nullptr) {
        //!!! Лучше писать так:
        //!!! typedef void (*FuncType)(int*, int);
        //!!! FuncType sortAlgo = (FuncType)GetProcAddress(SortLib, "Sort");
        
        void (*sortAlgo)(int*, int);
        sortAlgo = (void(*)(int*, int))(GetProcAddress(SortLib, "Sort"));
        
        //!!! Нет проверки sortAlgo на nullptr. Вдруг такой функции нет в dll.
        
        sortAlgo(array, n);
        FreeLibrary(SortLib);
        cout << "Result of sort algo from dynamic lib with explicit link:\n";
        OutputArray(array, n);

    }
    else {
        cout << "Error. Dexplicit.dll not found.\n";
    }
    
    cout << "Put enter to exit: ";
    getchar();
    getchar();
    delete[] arrayForImplicitDll;
    delete[] arrayForStaticLib;
    delete[] array;
    return 0;
}

