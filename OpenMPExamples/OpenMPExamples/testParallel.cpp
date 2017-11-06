//
//  testParallel.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 10/30/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//  g++-7 testParallel.cpp -fopenmp
#include <iostream>
#include <omp.h>

int main(){
#pragma omp parallel
    {
        // Code inside this region runs in parallel, numero de Hello = num de cores
        printf("Hello!\n");
    }
    
    //Inicializa el team de threads y divide el for
#pragma omp parallel for
    for(int n=0; n<10; ++n) printf(" %d", n);
    printf(".\n");

}
