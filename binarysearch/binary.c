//Assignment 3, Programming part, qt 3//

#include<stdio.h>
 
int binarySearch(int arr[], int low, int high)  //function for binary search
{
    if(high >= low)
    {
        int mid = (low + high)/2;               //getting the mid value
        if(mid == arr[mid])
            return mid;
        if(mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid -1));
    }
    return 0;
}

int main()  
{  
    int arr[100], i, a;                        //Hardcoding capacity of array as 100
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d Numbers: ", n);
    for(i = 1; i< n; i++)
    scanf("%d", &arr[i]); 
    
    a=binarySearch(arr, 1, n-1);               //getting value from binarySearch
    if(a != 0)
    printf("Index with a[i] = i is %d\n", a);  //if we get some value from binarySearch
    else
    printf("There is no such index\n");        //if we get no value from binarySearch
    getchar();
    return 0;
}