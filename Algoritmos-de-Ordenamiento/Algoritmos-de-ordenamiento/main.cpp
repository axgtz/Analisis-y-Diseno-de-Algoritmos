//  Algoritmos-de-ordenamiento
//
//  Created by Alex Gutz on 8/27/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
#include <iostream>

using namespace std;
/*
YA:
 Print
 
FALTAN:
GLOBAL VARIABLES
SWAP
MANERA DE CALC EL TIEMPO
RANDOMIZER
 
Ordenamiento de burbuja 	(Bubble Sort)
Ordenamiento de burbuja bidireccional (Cocktail Sort)
Ordenamiento por inserción (Insertion Sort)
Ordenamiento por casilleros (Bucket Sort)
Ordenamiento por cuentas (Counting Sort)
Ordenamiento por mezcla (Merge Sort)
Ordenamiento con árbol binario(Binary tree Sort)
Ordenamiento Radix (Radix Sort)
Ordenamiento Shell (Shell Sort)
Ordenamiento por selección (Selection Sort)
Ordenamiento por montículos (Heap Sort)
Ordenamiento rápido (Quick Sort)
*/

#include <ctime>
#include <cstdlib>

int main()
{
    srand((unsigned)time(0));
    int random_integer;
    for(int index=0; index<1000000; index++){
        random_integer = (rand()%1000000)+1;
        cout << random_integer << endl;
    }
}
/*

void CocktailSort(int a[], int n){
    bool swapped = true;
    int start = 0;
    int end = n-1;
    
    while (swapped){
        swapped = false;
        
        for (int i = start; i < end; ++i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        
        swapped = false;
        
        --end;
        
        for (int i = end - 1; i >= start; --i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(int argc, const char * argv[]) {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    CocktailSort(arr,n);
    
    printf("Sorted array :\n");
    printArray(arr,n);
    
    return 0;
}*/
