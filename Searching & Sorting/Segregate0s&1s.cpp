#include <iostream>
using namespace std;

void segregate(int arr[], int n) { 
    
    int i, count = 0;
    for (i = 0; i < n; i++) {
    
        if (arr[i] == 0) 
            count++; 
    } 

    for (i = 0; i < count; i++) 
        arr[i] = 0; 

    for (i = count; i < n; i++) 
        arr[i] = 1; 
} 

void printSegregate(int arr[], int n) {

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 

int main() 
{ 
    int arr[] = { 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    segregate(arr, n); 
    printSegregate(arr, n); 
    return 0; 
} 
