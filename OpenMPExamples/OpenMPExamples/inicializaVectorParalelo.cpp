//
//  inicializaVectorParalelo.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 11/6/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//
#include <omp.h>
#include <iostream>
#define N 1000000

int main(){
    int i;
    float a[N];
    
    double suma = 0;
    
    double start_time = omp_get_wtime();
    
    //Inicializar vector
#pragma omp parallel for private(i) shared(a) schedule(dynamic, 1000)
    for(i=0; i < N; i++)
        a[i]= 1.0;
    
    double time = omp_get_wtime() - start_time;
    
    printf("Tiempo = %f\n\n", time );
    //Resolviendo el mismo problema con reducciones
#pragma omp parallel shared(suma,a) private(i)
    {
    #pragma omp for private(i) reduction(+:suma)
        for(i=0;i<N;i++){
            suma += a[i];
        }
    }
    
    printf("La suma total es = %f\n", suma);
    
    return 0;
}



