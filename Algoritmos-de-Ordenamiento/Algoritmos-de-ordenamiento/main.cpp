//  Algoritmos-de-ordenamiento
//
//  Created by Alex Gutz on 8/27/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <vector>

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

void printArray(){
    for (int i=0; i < tam; i++)
        cout << vec[i] << " ";
    cout << "\n";
}

//SWAP
void swap(int a,int b){
    int temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
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

///--------------------------------Sorts------------------------------
//---------------Selection Sort---------------
void selectionSort(){//Busca el minnimo y los va ponindo al principio
    int posMenor;

    for(int i = 0; i < tam;i++){
        posMenor = i;
        for(int j = i + 1 ; j < tam ; j++){
            if(vec[posMenor] > vec[j]){//Se encuentra uno menor que el num seleccionado
                posMenor = j;
            }
        }
        swap(i,posMenor);
    }
    
}

//---------------Insertion Sort---------------
void insertionSort() {
    int j;
    for (int i = 1; i < tam; i++) {
        j = i;
        while (j>0 && vec[j-1] > vec[j]) {
            swap(j, j-1);
            j--;
        }
    }
}

//---------------BubleSort---------------
void bubbleSort()
{
    int i, j;
    for (i = 0; i < tam-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < tam-i-1; j++)
            if (vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
}

//---------------QuickSort---------------
int particion(int lo, int hi) {//Regresa el indice donde quedo el pivote
    //Arregla los subarreglos tomando en cuenta el pivote
    int pivote = vec[lo];
    lo--;
    hi++;
    
    while (true) {
        do{
            lo++;
        }while (pivote > vec[lo]);
        do {
            hi--;
        } while (pivote < vec[hi]);
        
        if (lo >= hi) {
            return hi;
        }
        else {
            swap(lo, hi);
        }
    }
}

void quickSort(int lo, int hi) {
    int p; 	//pivote
    if(hi > lo){
        p = particion(lo, hi);  //Pone el pivote en donde debe de estar en el arreglo y todos
        //los nums menor al pivote estan antes y los mayores después
        //Lamar de forma recursiva a quicksort, no se incluye el pivote porque ya esta acomodado
        quickSort(lo, p);
        quickSort(p + 1, hi);
    }
}


//---------------MergeSort---------------
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

//---------------Cocktail Sort---------------
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

//---------------------ShellSort -------------------
int shellSort(){
    // Start with a big gap, then reduce the gap
    for (int gap = tam/2; gap > 0; gap /= 2){
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < tam; i += 1){
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = vec[i];
            
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
                vec[j] = vec[j - gap];
            
            //  put temp (the original a[i]) in its correct location
            vec[j] = temp;
        }
    }
    return 0;
}

//---------------------CountSort -------------------
void countingSort() {
    int i, j, k;
    int idx = 0;
    int min, max;
    
    min = max = vec[0];
    for(i = 1; i < tam; i++) {
        min = (vec[i] < min) ? vec[i] : min;
        max = (vec[i] > max) ? vec[i] : max;
    }
    
    k = max - min + 1;
    /* creates k buckets */
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;
    
    for(i = 0; i < tam; i++) B[vec[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) vec[idx++] = i;
    
    
    delete [] B;
}

//---------------------Tree Sort---------------------
struct Node{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item){
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(Node *root, int vec[], int &i){
    if (root != NULL){
        storeSorted(root->left, vec, i);
        vec[i++] = root->key;
        storeSorted(root->right, vec, i);
    }
}

Node* insert(Node* node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) Node pointer */
    return node;
}

void treeSort(){
    struct Node *root = NULL;
    
    // Construct the BST
    root = insert(root, vec[0]);
    for (int i=1; i<tam; i++)
        insert(root, vec[i]);
    
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, vec, i);
}

//---------------------RadixSort -------------------
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};
    
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (i = n - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(){
    int m = getMax(vec, tam);

    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(vec, tam, exp);
}

//---------------------BucketSort -------------------
void bucketSort(){
    vector<int> b[tam];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<tam; i++)
    {
        int bi = (tam*vec[i])%tam; // Index in bucket
        b[bi].push_back(vec[i]);
    }
    
    // 3) Sort individual buckets
    for (int i=0; i<tam; i++)
        sort(b[i].begin(), b[i].end());
    
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < b[i].size(); j++)
            vec[index++] = b[i][j];
}

//---------------------Heap Sort---------------------
void heapify(int *array, int n, int root) {
    int largest = root;
    int left = (2 * root) + 1;
    int right = (2 * root) + 2;
    
    if(left < n && array[left] > array[largest]) {
        largest = left;
    }
    if(right < n && array[right] > array[largest]) {
        largest = right;
    }
    
    if(largest != root) {
        swap(root, largest);
        heapify(array, n, largest);
    }
}

void heapSort() {
    for(int i = tam / 2 - 1; i >= 0; i--) {
        heapify(vec, tam, i);
    }
    for(int i = tam-1; i >= 0; i--) {
        swap(i, 0);
        heapify(vec, i, 0);
    }
}




int main(){
    string cantidad;
    cout << "Cuantos datos quieres procesar? Favor de Ingresar el numero:" << endl;
    cin >> cantidad;
    lecturaDatos(cantidad);
    
    clock_t cl = clock();
    
    heapSort();
    //bucketSort();
    //radixsort();
    //treeSort();
    //countingSort();
    //shellSort();
    //quickSort(0, tam-1);
    //selectionSort();
    //insertionSort();
    //bubbleSort();
    //MergeSort(vec, 0, tam-1);
    //CocktailSort();
    
    double tiempo = (clock()-cl)*1000/CLOCKS_PER_SEC;

    printArray();
    
    cout << "Tiempo de ejecucion: " <<  tiempo << " ms" << endl;
    
    return 0;
}
