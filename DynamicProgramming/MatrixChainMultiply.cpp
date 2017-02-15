#include <iostream>
#include "array_utils.h"
using namespace std;

#include <stdio.h>
#include <limits.h>

// recursive
int MatrixChainOrder(int arr[], int i, int j){

    if(i==j)
        return 0;
    if(i==j-1)
        return arr[i-1]*arr[i]*arr[j];

    int minOp=INT_MAX, l;

    for(int k=i+1; k<j; k++){
        int tmp;
        tmp=MatrixChainOrder(arr, i,k)+MatrixChainOrder(arr, k+1, j)+arr[i-1]*arr[k]*arr[j];

        if(minOp>tmp){
            minOp=tmp;
            l=k;
        }
    }
    // cout<<i<<' '<<l<<' '<<j<<endl;
    return minOp;
}

// bottom-up
int MatrixChainOrder_bup(int arr[], int n){
    int M[n][n];
    if(n==1)
        return 0;
    for(int i=1; i<n-1;++i){
        M[i][i+1]=arr[i-1]*arr[i]*arr[i+1];
    }
    for(int i=0;i<n;++i)
        M[i][i]=0;

    for(int j=3; j<n; ++j){
        for(int k=2; k<j; ++k){
            M[1][j]=M[1][k]+M[k+1][j]+arr[0]*arr[k]*arr[j];
        }
    }

    // JL::print_array2d(&M[0][0], n, n);

    return M[1][n-1];
}
 
// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, n-1));
    printf("Minimum number of multiplications is %d ", MatrixChainOrder_bup(arr, n));
 
    return 0;
}