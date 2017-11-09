//
//  factorialParalelo.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 11/9/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//  g++-7 factorialParalelo.cpp -fopenmp
#include <iostream>
#include <omp.h>

int main(){
    int fact;
    printf("Favor de introducir numero a calcular en factorial: \n");
    std::cin >> fact;
    if(fact < 1){
        printf("\nFavor de introducir numero mas grande");
        return 0;
    }
    int total = 1,n;
    //Inicializa el team de threads y divide el for
#pragma omp parallel for shared(fact) private(n) reduction(*:total)
        for(n=2; n<=fact; n++)
            total*=n;
    
    printf("\nRes: %d",total);
    
    return 0;
}

