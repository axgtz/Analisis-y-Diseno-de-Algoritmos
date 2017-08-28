//  main.cpp
//  BrickSort
//
//  Created by Alex Gutz on 8/28/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
#include <iostream>

using namespace std;

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


// A function to sort the algorithm using Odd Even sort
void oddEvenSort(int arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted
    while (!isSorted)
    {
        isSorted = true;
        
        // Perform Bubble sort on ODD indexed element
        for (int i=1; i<n-1; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                printArray(arr, n);
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
        
        // Perform Bubble sort on EVEN indexed element
        for (int i=0; i<n-1; i=i+2)
        {
            if (arr[i] > arr[i+1])
            {
                printArray(arr, n);
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
    
    return;
}


// Driver program to test above functions.
int main()
{
    /*
    int arr[] = {1,9,3,10,15,18,14,13,8,2,7,11,6,19,4,17,5,12,20,16};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    oddEvenSort(arr, n);
    printArray(arr, n);*/
    
    return (0);
}
