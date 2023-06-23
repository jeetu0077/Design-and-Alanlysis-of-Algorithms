//Assignment 3, Programming part, qt 2//

#include <stdio.h>

void swap(int a[], int n, int m) {                         // Swap function is used to get the elements in their sorted positions.
    a[n] = a[n] + a[m];
    a[m] = a[n] - a[m];
    a[n] = a[n] - a[m];
}                             

void coolSort(int A[], int H[], int n, int m) {
    for (int i = 0; i < m; i++) {                         //This for loop is for the values of H.
        int step = H[i];

        for (int start = 0; start < step; start++) {      //initiating from start. 
            int indexSub = start + step;                  //defining indexSub which is sum of start and step.
            while (indexSub < n) {                        //the last element should be less than n, i.e if we start from a1 then we get a1 and a6, not a11 as it is greater than n,which is hardcoded to 10.
                int j = indexSub;
                while (j > start && A[j] < A[j - step]) { //swapping the elements. Ex- In the first pass of H=5, we get a1 and a6, if a6 is smaller than a1, we swap a1 and a6.

                    swap(A, j, j - step);
                    j -= step;                            //decrementing j. Ex- H=3, in the first pass we get a1,a4,a7,a10. a10 is compared with a7, if it is small we swap. Then j is decremented , so we compare a7 and a4 and so on..
                    }
                    indexSub += step;                     // After 1st pass of H=5 we increment start by 1 , so we start from a2 , so now we get a2,a7. We continue till the end.
                }
        }
    }
    return;
}

int main()
{
    int A[] = { 2, 5, 6, 4, 10, 9, 8, 1, 10, 5}; 
    int H[] = { 5, 3, 1 };                                // Taking the test case 1 , 2nd test case is A[] = { 2, 5, 9, 4, 10, 7, 8, 1, 11, 5 }, H[] = { 5, 2, 1 }. You can execute case 2 by changing the inputs.
    int n, m;
    
    coolSort(A, H, 10, 3);                                // Values of n and m are hardcoded to 10 and 3, i.e number of elements in the array are 10 and the elements in the sequence are 3.
    for (int i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}