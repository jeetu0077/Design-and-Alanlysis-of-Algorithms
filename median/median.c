//Assignment 3, Programming part, qt 1c//

#include<stdio.h>

void SelectionSort(int arr[], int n, int k)  
{  
    int i, j, min;  
    for (i = 0; i < k; i++){  
        min = i;                                 //minimum element in the unsorted array  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min])  
            min = j;  
     
    int temp = arr[min];  
    arr[min] = arr[i];  
    arr[i] = temp;  
    }                                           // Swapping the minimum element with the first element
}  
  
void Arr(int a[], int n)                        // function to print the array   
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d ", a[i]);  
} 

float Find_median(int array[] , int n)          // function to find the median of the input array
{
    float median=0;
    if(n%2 == 0)                                // if number of elements are even
        median = (array[(n-1)/2] + array[n/2])/2.0;
    else                                        // if number of elements are odd
        median = array[n/2];
    return median;
}

int main() 
{  
    int a[100], i, k;
    float median = 0;
    int n = sizeof(a) / sizeof(a[0]); 
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d Numbers: ", n);
    for(i = 0; i< n; i++)
    scanf("%d", &a[i]);
    
    median = Find_median(a, n);                // performing the Find_median function
    printf("\n\nThe median is : %f\n",median);
    
    printf("\nEnter the value of k:");         //taking value from the user
    scanf("%d", &k);
     
    SelectionSort(a, n, k);                    //performing the SelectionSort function 
    printf("\nThe sorted array is: ");    
    Arr(a, k);
 

    return 0;  
} 