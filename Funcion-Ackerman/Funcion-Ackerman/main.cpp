//
//  main.cpp
//  Funcion-Ackerman
//
//  Created by Alex Gutz on 8/17/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

double Ack(int m,int n){
    if(m==0){
        return n+1;
    }else if(m>0 && n==0){
        return Ack(m-1,1);
    }else{
        return Ack(m-1,Ack(m,n-1));
    }
}

int main(int argc, const char * argv[]) {
   
    std::cout << Ack(4,3) << std::endl;
    
    
    return 0;
}
