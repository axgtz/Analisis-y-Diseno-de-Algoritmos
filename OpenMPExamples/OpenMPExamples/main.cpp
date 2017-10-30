//
//  main.cpp
//  OpenMPExamples
//
//  Created by Alex Gutz on 10/30/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
//

#include <cmath>
int main()
{
    const int size = 256;
    double sinTable[size];
    
#pragma omp parallel for
    for(int n=0; n<size; ++n)
        sinTable[n] = std::sin(2 * M_PI * n / size);
    
    // the table is now initialized
}
