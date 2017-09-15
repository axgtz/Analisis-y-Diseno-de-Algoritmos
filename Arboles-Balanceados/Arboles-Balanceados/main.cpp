//  Arboles-Balanceados
//
//  Created by Alex Gutz on 9/10/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include <iostream>

#include "RBT.hpp"

#include "AVLTree.h"
//Librerias de lectura de datos
#include <fstream>
#include <sstream>
//Random
#include <chrono>
//Floor
#include <math.h>
//Time
#include <ctime>
//Shuffle
#include <algorithm>

using namespace std;
using namespace std::chrono;

//Generar Archivod e 100000 sin repetidos
int tam = 100000;
int * vec = new int[tam];

//SWAP
void swapT(int a,int b){
    int temporal = vec[b];
    vec[b] = vec[a];
    vec[a] = temporal;
}


//SHUFFLE
void maShuffle(int tam){        //Version mejorada del Durstenfeld el cual es una version mejorada del
    //Iniciar seed              //Fisher-Yates algorithm con complejidad O(n), en comparación con O(n^2)
    srand ( unsigned ( time(0) ) );
    
    for (int i = tam - 1; i > 0; i--) {
        int index = floor(rand()%i);
        swapT(i, index);
    }
}

void numRandNotRepeated(int tam){
    ofstream myfile;
    string fileName = to_string(tam);
    myfile.open ( fileName + ".txt");
    
    myfile << tam << '\n';  //Se guarda la cantidad de numeres a genera al principio
    
    for(int index=1; index<=tam; index++){
        vec[index] = index;
    }
    maShuffle(tam);
    
    for(int index=0; index<tam; index++){
        myfile << vec[index] << '\n';
    }
    
    myfile.close();
}

int main(){
    //numRandNotRepeated(tam);
    
    RedBlack<int,int> tree;
    
    ifstream archivo_entrada; //Declarar variable que se usa para acceder a las funciones de ifstream
    archivo_entrada.open("100000.txt");
    
    if (archivo_entrada.fail()) {
        cout << "Error al abrir el archivo" << endl;

        return 0;
    }
    
    char linea[128];
    
    //Usando la variable linea se extrae toda la primera linea del archivo de texto
    archivo_entrada.getline(linea, sizeof(linea));
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 0;i<100000;i++) {
        archivo_entrada.getline(linea, sizeof(linea));
        tree.Insert(stoi(linea),stoi(linea));
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    cout << "Tiempo de ejecucion: " << time_span.count()  << "seconds" << endl;
    archivo_entrada.close();
    
    //Busqueda 1
    t1 = high_resolution_clock::now();
    tree.Find(10);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 1: " << time_span.count()  << "seconds" << endl;
    
     //Busqueda 2
    t1 = high_resolution_clock::now();
    tree.Find(99999);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 2: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 3
    t1 = high_resolution_clock::now();
    tree.Find(34718);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 3: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 4
    t1 = high_resolution_clock::now();
    tree.Find(666);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 4: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 5
    t1 = high_resolution_clock::now();
    tree.Find(13000);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
     cout << "Busq 5: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 6
    t1 = high_resolution_clock::now();
    tree.Find(60000);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 6: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 7
    t1 = high_resolution_clock::now();
    tree.Find(80570);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 6: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 8
    t1 = high_resolution_clock::now();
    tree.Find(43263);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 6: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 9
    t1 = high_resolution_clock::now();
    tree.Find(32055);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 6: " << time_span.count()  << "seconds" << endl;
    
    //Busqueda 10
    t1 = high_resolution_clock::now();
    tree.Find(8729);
    t2 = high_resolution_clock::now();
    time_span = duration_cast<duration<double> >(t2 - t1);
    cout << "Busq 10: " << time_span.count()  << "seconds" << endl;
    
    //printPretty(tree, 1, 0, cout);
    
    //tree.Dump();
    
    int xx;
    cin >> xx;
    return 0;
}

