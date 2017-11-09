//
//  main.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 10/30/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//  g++-7 main.cpp -fopenmp
#include <omp.h>
#include <iostream>
#define N 1000000

int main(){
    int i;
    float a[N];
    //int n_procs;
    
    int tid;
    int n_threads;
    
    double suma = 0;
    //Inicializar vector
    for(i=0; i < N; i++)
        a[i]= 1.0;
    
    
#pragma omp parallel num_threads(3) shared(suma,a,	n_threads) private(tid,i)
    {
        //n_procs = omp_get_num_procs();
        
        //printf("Procs : %d\n", n_procs);
        
        n_threads = omp_get_num_threads();
        
        tid = omp_get_thread_num();
        
        int bloque = N / n_threads;
        
        int inicio = (tid * bloque);
        
        int fin = inicio +bloque;
        
        if(tid = (n_threads -1)){fin=N;}//Garantizas que sume todo aunque sea impar el numero de threads
        
        double suma_local = 0;
        
        for(i = inicio; i < fin; i++){
            suma_local += a[i];
        }
        
        printf("La suma local del hilo %d es = %f\n",tid, suma_local);
#pragma omp critical
        {
        suma = suma + suma_local;
        }
    }
    printf("La suma total es = %f\n\n", suma);
    
    //Resolviendo el mismo problema con omp for
    
    suma = 0;
    
#pragma omp parallel num_threads(3) shared(suma,a) private(tid,i)
    {
        tid = omp_get_thread_num();
        
        double suma_local = 0;
        
        #pragma omp for private(i)
        for(i=0;i<N;i++){
            suma_local += a[i];
        }
        
        printf("La suma local del hilo %d es = %f\n",tid, suma_local);
        
        #pragma omp critical
        {
            suma = suma + suma_local;
        }
    }
    
    printf("La suma total es = %f\n\n", suma);

    //Resolviendo el mismo problema con reducciones
    
    suma = 0;
    
#pragma omp parallel num_threads(3) shared(suma,a) private(i)
    {
    #pragma omp for private(i) reduction(+:suma)
        for(i=0;i<N;i++){
            suma += a[i];
        }
        
        printf("La suma local del hilo %d es = %f\n",tid, suma);
        
    }
    
    printf("La suma total es = %f\n", suma);
    
    return 0;
}












