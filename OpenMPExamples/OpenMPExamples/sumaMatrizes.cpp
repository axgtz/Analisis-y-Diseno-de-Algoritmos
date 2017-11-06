//
//  sumaMatrizes.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 11/6/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//
#include <omp.h>
#include <iostream>
#define N 10

int main(){
    int i,j;
    int a[N][N];
    int b[N][N];
    
    int suma[N][N];
    
    double start_time = omp_get_wtime();
    
    //Inicializar vector
#pragma omp parallel for private(i,j) shared(a,b) schedule(dynamic, 1000)
    for(i=0; i < N; i++){
        for(j=0; j < N; j++){
            a[i][j]= 1;
            b[i][j]= 2;
        }
    }
    
    double time = omp_get_wtime() - start_time;
    
    printf("Tiempo = %f\n\n", time );

#pragma omp parallel shared(suma,a,b) private(i,j)
    {
#pragma omp for private(i)
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                suma[i][j]=a[i][j]+b[i][j];
            }
        }
    }
    
    //Imprimir
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf(" %d",suma[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
