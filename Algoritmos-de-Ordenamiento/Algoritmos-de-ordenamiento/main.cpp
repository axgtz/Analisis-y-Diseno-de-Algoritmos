//  Algoritmos-de-ordenamiento
//
//  Created by Alex Gutz on 8/27/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
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

void printArray()
{
    for (int i=0; i < tam; i++)
        cout << vec[i] << " ";
    cout << "\n";
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
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
        vec[0] = 0;
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

///--------------------Sorts---------------
//BubleSort
void bubbleSort()
{
    int i, j;
    for (i = 0; i < tam-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < tam-i-1; j++)
            if (vec[j] > vec[j+1])
                swap(&vec[j], &vec[j+1]);
}

//MergeSort
void Merge(int *a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
    
    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    
    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    
    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    
    
    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i-low];
    }
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Split the data into two half.
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        
        // Merge them to get sorted output.
        Merge(a, low, high, mid);
    }
}

//Cocktail Sort
void CocktailSort(){
    bool swapped = true;
    int start = 0;
    int end = tam-1;
    
    while (swapped){
        swapped = false;
        
        for (int i = start; i < end; ++i){
            if (vec[i] > vec[i + 1]){
                swap(vec[i], vec[i+1]);
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        
        swapped = false;
        
        --end;
        
        for (int i = end - 1; i >= start; --i){
            if (vec[i] > vec[i + 1]){
                swap(vec[i], vec[i+1]);
                swapped = true;
            }
        }
        ++start;
    }
}

int main(){
    string cantidad;
    cout << "Cuantos datos quieres procesar? Favor de Ingresar el numero:" << endl;
    cin >> cantidad;
    lecturaDatos(cantidad);
    
    clock_t cl = clock();
    bubbleSort();
    //MergeSort(vec, 0, tam-1);
    //CocktailSort();
    
    double tiempo = (clock()-cl)*1000/CLOCKS_PER_SEC;

    printArray();
    
    cout << "Tiempo de ejecucion: " <<  tiempo << " ms" << endl;
    
    return 0;
}
