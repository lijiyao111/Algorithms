#include <stdio.h>
#include <climits>
#include <iostream>
#include "array_utils.h"
using namespace std;


int cutRod(int price[], int length[], int n){
  // if(n<0)
  //   return INT_MIN;

  if(n==0)
    return 0;

  int maxP=INT_MIN;

  for(int i=0; i<n; ++i){
    int tmp=cutRod(price, length, n-length[i])+price[i];
    maxP=tmp>maxP? tmp: maxP;
  }

  return maxP;
}

int cutRod_bup(int price[], int length[], int n){

  int cutPrice[n+1];

  for(int i=0; i<n+1; ++i){
    cutPrice[i]=0;
  }

  for(int i=0; i<n; ++i){
    if(length[i]<=n)
      cutPrice[length[i]]=price[i];

  }
  // JL::print_array1d(cutPrice,n+1);

  for(int i=length[0]; i<=n; ++i){
    int maxP=INT_MIN;

    for(int j=length[0]; j<=i; ++j){
      int tmp=cutPrice[j]+cutPrice[i-j];
      if(maxP<tmp)
        maxP=tmp;
    }
    cutPrice[i]=maxP;
  }

  // JL::print_array1d(cutPrice,n+1);
  return cutPrice[n];
}
 
/* Driver program to test above functions */
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<size<<endl;
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, length, size));
    // printf("Maximum Obtainable Value is %d\n", cutRod_bup(arr, length, 4));

    return 0;
}