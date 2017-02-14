#include <stdio.h>
#include <algorithm> 

// bottom-up
int knapSack_bup(int w, int wt[], int val[], int n){
  int V[n+1][w+1];

  for(int i=0; i<=n; ++i){
    for(int j=0; j<=w; ++j){
      if(i==0||w==0)
        V[i][j]=0;
      else if(wt[i-1]>j)
        V[i][j]=V[i-1][j];
      else
        V[i][j]=std::max(V[i-1][j], V[i-1][j-wt[i-1]]+val[i-1]);
    }
  }
  return V[n][w];
}


// recursive
int knapSack(int w, int wt[], int val[], int n){
  if(n==0||w==0)
    return 0;

  if(wt[n-1]>w)
    return knapSack(w, wt, val, n-1);
  else
    return std::max(knapSack(w, wt, val, n-1), knapSack(w-wt[n-1], wt, val, n-1)+val[n-1]);
}
 
// Driver program to test above function
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 25};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    // printf("%d", knapSack(W, wt, val, n));
    printf("%d", knapSack_bup(W, wt, val, n));
}