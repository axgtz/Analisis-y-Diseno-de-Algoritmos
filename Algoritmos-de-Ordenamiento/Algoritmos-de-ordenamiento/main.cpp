//  Algoritmos-de-ordenamiento
//
//  Created by Alex Gutz on 8/27/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
/*
YA:
 Print
 GLOBAL VARIABLES
 SWAP
 RANDOMIZER
 
FALTAN:

MANERA DE CALC EL TIEMPO

 
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
#include <iostream>

#include <ctime>
#include <cstdlib>

//Librerias de lectura de datos
#include <fstream>
#include <sstream>

//Library import for random generation
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

//Global Variables
int tam;
int *vec;

void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

//Random number Generator and file creator/populator
void genRand(int tamRand){
    int random_integer;
    srand(time( NULL ));
    
    ofstream myfile;
    string fileName = to_string(tamRand);
    myfile.open ( fileName + ".txt");
    
    myfile << tamRand << '\n';  //Se guarda la cantidad de numeres a genera al principio

    for(int index=0; index<tamRand; index++)
    {
        random_integer = (rand()%tamRand)+1;
        myfile << random_integer << '\n';
    }
    myfile.close();
}

void lecturaDatos(string nombreArchivo) {
    ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream
    
    string st = nombreArchivo + ".txt";
    
    archivo_entrada.open(st);
    
    if (archivo_entrada.fail()) {
        cout << "Error al abrir el archivo" << endl;
        vec[0] = -1;
        tam = 1;
        return;
    }
    
    char linea[128];
    
    //Usando la variable linea se extrae toda la primera linea del archivo de texto
    archivo_entrada.getline(linea, sizeof(linea));
    
    //Se guarda el numero de numeros que va a contener el arreglo en el atributo de la clase entera "tam"
    if ( !(istringstream(linea) >> tam) ){
        tam = 0;
        cout << "Error al leer el tamaño del arreglo en el archivo de texto" << endl;
    }
    
    
    vec = new int[tam];
    
    
    for (int i = 0;i<tam;i++) {
        archivo_entrada.getline(linea, sizeof(linea));
        vec[i] = stoi(linea);
    }
    
    archivo_entrada.close();
}

int main(){
    genRand(100000);
    
    return 0;
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

int main(int argc, const char * argv[]) {
    int arr[] = {5, 1, 4, 2, 8, 0, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    
    CocktailSort(arr,n);
    
    printf("Sorted array :\n");
    printArray(arr,n);
    
    return 0;
}*/
