//  Arboles-Balanceados
//
//  Created by Alex Gutz on 9/10/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//
#include <iostream>
#include <time.h>
#include "ArbolB.h"

#include <ctime>
#include <chrono>

using namespace std::chrono;

int main(int argc, const char * argv[]) {
    
    int orden = 3;
    srand((int)time(NULL));
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    ArbolB<int> * arbol = new ArbolB<int>(orden);
    //ArbolDosTres<int> * arbol2 = new ArbolDosTres<int>();
    //arbol2->setRaiz(10);
    //arbol2->printAsc();

    
    
    for(int i = 0; i< 100000;i++){
        arbol->Insertar(rand()%10000);
    }
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);
    
    cout << "Tiempo de ejecucion: " << time_span.count()  << "seconds" << endl;
    
    //auto begin = std::chrono::high_resolution_clock::now();
    //auto end = std::chrono::high_resolution_clock::now();
    //auto tiempo = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
    
    clock_t t;
    for (int i = 0; i < 10;i++){
        //begin = std::chrono::high_resolution_clock::now();
        t = clock();
        arbol->Buscar(rand() % 1000);
        //end = std::chrono::high_resolution_clock::now();
        t = clock() - t;
        t = ((float)t)*1000;
        //tiempo = std::chrono::duration_cast<std::chrono::milliseconds>(end-begin);
        //std::cout << "Busqueda " << i+1 << ": "<< tiempo.count() << " ms"<< std::endl << endl;
        std::cout << "Busqueda " << i+1 << ": " << (((float)t)/ CLOCKS_PER_SEC) << endl;
    }
    
    //    Imprime:
    //    arbol->printAsc();
    //    arbol->printDesc();
    
    
    
    
    return 0;
    
}
