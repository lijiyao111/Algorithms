// Bottom-up, time: O(n^2), space: O(n)
// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

#include<stdio.h>
#include<stdlib.h>
#include "../array_utils.h"

int lis(int arr[], int n){
    int * lisv= new int [n];

    for (int i=0; i<n; ++i){
        lisv[i]=1;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<i; ++j){
            if(arr[j]<arr[i]&&lisv[j]+1>lisv[i])
                lisv[i]=lisv[j]+1;
        }
    }

    int maxlis=0;
    for(int i=0;i<n; ++i){
        maxlis = lisv[i]>maxlis? lisv[i]:maxlis;
    }

    JL::print_array1d(lisv, n);


    delete [] lisv;

    return maxlis;

}
 

 
// Driver program to test the functions above
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of LIS is %d\n", lis( arr, n ));
    return 0;
}