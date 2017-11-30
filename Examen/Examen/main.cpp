//
//  main.cpp
//  Examen
//
//  Created by Alex Gutz on 11/27/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
#include <cmath>
#include <iostream>
int matrix[4][6];
///------ P1- Num Triangular ------///
bool numTriangular(int num){
    int i = 1;
    while(num > 0){
        num = num-i;
        i++;
    }
    if(num == 0){
        return true;
    }
    return false;
}
///------ P2- Func Sum ------///
float funcion(float numOG){
    float numCalc=0;
    for(int i = 1;i <= numOG;i++){
        numCalc = numCalc + (numOG + (2/numOG) * i);
    }
    return numCalc;
}
///------ P3- Ordenamiento de matriz ------///
int particion(int l, int r, int c) {
    int i, pivote = matrix[l/c][l%c];    //Primer num de pivote
    std::swap(matrix[l/c][l%c], matrix[r/c][r%c]);//Pivote mover al final final
    int j = l;
    for (i = l; i < r; i++) {
        if (matrix[i/c][i%c] <= pivote) {//Si el pivote es igual o mayor, cambiar
            std::swap(matrix[i/c][i%c], matrix[j/c][j%c]);
            j++;
        }
    }
    
    // Move pivot to its place.
    std::swap(matrix[j/c][j%c], matrix[r/c][r%c]);//Pivote mover al final final
    
    return j;
}

void quicksort(int l, int r, int c) {
    int pivote;
    if (r>l) {
        pivote = particion(l, r, c);
        quicksort(l, pivote-1, c);
        quicksort(pivote+1, r, c);
    }
}

///------ P4- Bits  ------///Calcula operaciones necesarias
int bitsCalcOP(int numBits){
    int res = 0;
    for(int i = 0;i<numBits;i++){
        res = res + pow(2, i) * (numBits-i);
    }
    return res;
}
///------ P5- Red de Ordenadores ------///



int main(int argc, const char * argv[]) {
    ///------ P1- Num Triangular ------///
    /*
    for(int i = 0;i<22;i++){
        std::cout << i << "  " <<numTriangular(i) << std::endl;
    }*/
    
    ///------ P2- Func Sum ------///
    
    for(int i = 1;i<5;i++){
        std::cout << i << "  " <<funcion(i) << std::endl;
    }
    
    ///------ P3- Multiplicación de matriz ------///
    //Iniciar Matriz con numeros rand
    /*int col = 6; int row = 4;
    int i,j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            matrix[i][j] = random() % 10;
        }
    }

    
    //Imprimir Matriz
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    quicksort(0, row * col - 1, col);
    printf("\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/
    ///------ P4- Bits ------///
    //std::cout << bitsCalcOP(4) << "\n";
    
    ///------ P5- Red de Ordenadores ------///

    
    return 0;
}





