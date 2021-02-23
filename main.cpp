#include <iostream>
#include "DynSort.h"
#include "staticlb.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>

typedef void (*SortFunction)(int*, int);

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
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    srand(time(nullptr));
    int n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    int* array = new int[n];
    GenerateArray(array, n);
    int* arrayForStaticLib = CopyArray(array, n);
    int* arrayForImplicitDll = CopyArray(array, n);

    std::cout << "Input array:\n";
    OutputArray(array, n);

    Sort(arrayForStaticLib, n);
    SortDyn(arrayForImplicitDll, n);
    std::cout << "Result of Sort algo from static lib:\n";
    OutputArray(arrayForStaticLib, n);
    std::cout << "Result of Sort algo from dynamic lib with implicit link:\n";
    OutputArray(arrayForImplicitDll, n);

    HINSTANCE SortLib = LoadLibrary(TEXT(".\\..\\Dynamic_lib\\Debug\\Dynamic.dll"));
    if (SortLib != nullptr) {
        SortFunction sortAlgo = (SortFunction) GetProcAddress(SortLib, "SortDyn");


        if (sortAlgo == nullptr) {
            std::cout << "Function with name \"SortDyn\" not found in Dynamic.dll\n";
        } else {
            sortAlgo(array, n);
            std::cout << "Result of Sort algo from dynamic lib with explicit link:\n";
            OutputArray(array, n);
        }

        FreeLibrary(SortLib);
    }
    else {
        std::cout << "Error. Dexplicit.dll not found.\n";
    }

    std::cout << "Put enter to exit: ";
    getchar();
    getchar();
    delete[] arrayForImplicitDll;
    delete[] arrayForStaticLib;
    delete[] array;
    return 0;
}
