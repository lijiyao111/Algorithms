#include <stdio.h>


// recursive
int numchange(int arr[], int m, int n){
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(m<1&&n>0)
        return 0;
    return numchange(arr, m-1, n)+numchange(arr, m, n-arr[m-1]);
}

// bottom-up

 
// Driver program to test above function
int main()
{
    int i, j;
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    printf("%d ", numchange(arr, m, 4));
    return 0;
}