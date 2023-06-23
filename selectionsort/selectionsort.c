//Assignment 3, Programming part, qt 1a//

#include<stdio.h>

void SelectionSort(int arr[], int n)  
{  
    int i, j, min;  
    for (i = 0; i < n-1; i++){  
        min = i;                              //minimum element in the unsorted array  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min])  
            min = j;  
     
    int temp = arr[min];  
    arr[min] = arr[i];  
    arr[i] = temp;  
    }                                        // Swapping the minimum element with the first element
}  
  
void Arr(int a[], int n)                     // function to print the array  
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
} 

int main()  
{  
    int a[100], i;                       //Hardcoding capacity of array as 100
    int n = sizeof(a) / sizeof(a[0]); 
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d Numbers: ", n);
    for(i = 0; i< n; i++)
    scanf("%d", &a[i]);                    //Taking the elements of the array from the user
     
    SelectionSort(a, n);                   //Applying the function SelectionSort
    printf("\n The sorted array is: ");    
    Arr(a, n); 
    return 0;  
}   