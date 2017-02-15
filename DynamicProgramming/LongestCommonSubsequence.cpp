// http://www.geeksforgeeks.org/fundamentals-of-algorithms/#DynamicProgramming
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include "array_utils.h"

// Recursive, slow
int lcs(char * X, char *Y, int m, int n){
  if(m<1 || n<1) 
    return 0;

  if(X[m]==Y[n])
    return 1+lcs(X, Y, m-1, n-1);
  else
    return std::max(lcs(X, Y, m-1, n), lcs(X, Y, m, n-1));
}

// Bottom-up DP, time: O(n^2), space: O(n^2)
int lcs_bup(char * X, char *Y, int m, int n){
  int lcs_tb[m+1][n+1];

  for(int i=0; i<m+1; ++i){
    for(int j=0; j<n+1; ++j){
      lcs_tb[i][j]=0;
    }
  }

  for(int i=1;i<=m;++i){
    for(int j=1; j<=n; ++j){
      if(X[i-1]==Y[j-1])
        lcs_tb[i][j] = lcs_tb[i-1][j-1]+1;
      else
        lcs_tb[i][j] = std::max(lcs_tb[i-1][j], lcs_tb[i][j-1]);
    }
  }

  return lcs_tb[m][n];
}
 
 
/* Driver program to test above function */
int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
 
  int m = strlen(X);
  int n = strlen(Y);
 
  printf("Length of LCS is %d\n", lcs_bup( X, Y, m, n ) );
 
  return 0;
}