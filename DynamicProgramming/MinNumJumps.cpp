#include <iostream>
#include <climits>
#include <stdio.h>
#include <algorithm>
using namespace std;

// recursive
int minJumps(int arr[], int m, int n){

    if(m>=n)
        return 0;

    if(arr[m]==0)
        return INT_MAX;

    int minstep=INT_MAX;
    int mintmp;
    for(int i=m+1; i<=m+arr[m] && i<=n; ++i){
        mintmp=minJumps(arr, i, n);
        if(minstep>mintmp+1 && mintmp!=INT_MAX){
            minstep=mintmp+1;
        }

    }
    return minstep;
    
}

// bottom-up
int minJumps_bup(int arr[], int n){
    int *jumps = new int[n];

    jumps[0]=0;

    for(int i=1; i<n; ++i){
        jumps[i]=INT_MAX;
        for(int j=0; j<i; j++){
            if(arr[j]+j>=i && jumps[j]!=INT_MAX){
                jumps[i]=min(jumps[i], jumps[j]+1);
                break;
            }
        }
    }

    int out=jumps[n-1];
    delete[] jumps;
    return out;


}

// linear time DP
int minJumpsLinear(int arr[], int n)
{
  int *jumps = new int[n];  // jumps[n-1] will hold the result
  int i =1, j = 0;

  jumps[0] = 0;
  for (i = 1; i < n; ) { 

    // if i is out of range of arr[j], then increment j
    if (arr[j] + j < i && j < i) {

      j++;

    // else if i is within range of arr[j], 
    //   jumps for ith element would be jumps[j]+1
    } else if (arr[j] + j >= i && j < i) {

      jumps[i] = jumps[j] + 1;
      i++;

    } else {
      // printf("solution does not exist");
      delete[] jumps;
      return INT_MAX;
    }
  }

  // printf("jumps: ");
  // for (i = 0; i < n; i++) {
  //   printf("%d, ", jumps[i]);
  // }
  int out=jumps[n-1];
  delete[] jumps;
  return out;
}


// Driver program to test above function
int main()
{
  int arr[] = {0, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  // printf("Minimum number of jumps to reach end is %d ", minJumps(arr, 0, n-1));
  // printf("Minimum number of jumps to reach end is %d ", minJumps_bup(arr, n));
  printf("Minimum number of jumps to reach end is %d ", minJumpsLinear(arr, n));
  return 0;
}