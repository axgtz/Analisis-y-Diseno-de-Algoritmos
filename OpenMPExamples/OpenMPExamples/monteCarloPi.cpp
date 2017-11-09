//
//  monteCarloPi.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 11/9/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//  g++-7 monteCarloPi.cpp -fopenmp
#include <iostream>
#include <cstdlib>      //rand(), srand(), RAND_MAX
#include <ctime>        //ctime() for random numbers
#include <cmath>        //math functions
#include <omp.h>
#define N 1000

int main(){
    double coord_x, coord_y, total;
    int i, inside = 0;
    srand(time(NULL));   //Seed de time
    
#pragma omp parallel private(i,coord_x, coord_y) shared(inside)
    {
#pragma omp for private(i,coord_x, coord_y) 
        for(i=0; i<N; i++){
            coord_x = (double)rand() / (double)(RAND_MAX);
            coord_y = (double)rand() / (double)(RAND_MAX);
            printf("\n %d",coord_x);
            if(((coord_x*coord_x) + (coord_y*coord_y)) <= 1)
            {
                inside++;
            }
        }
        
        //Calculate PI
        total = inside/N;
        
        printf("\n Total: %d", total);
        
    }
    
    
    return 0;
}


