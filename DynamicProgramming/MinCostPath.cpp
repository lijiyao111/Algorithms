// http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include<stdio.h>
#include<limits.h>
#define R 3
#define C 3

#include <iostream>
using namespace std;



inline int min(int x, int y, int z){
    int tmp = x<y? x: y;

    return tmp< z? tmp: z;
}

// Bottom-up, time: O(mn)
int minCost(int cost[R][C], int m, int n){
    int path_cost[m+1][n+1];

    path_cost[0][0]=cost[0][0];

    for(int j=1; j<=n; ++j)
        path_cost[0][j]=cost[0][j]+path_cost[0][j-1];
    for(int i=1; i<=m; ++i)
        path_cost[i][0]=cost[i][0]+path_cost[i-1][0];

    for(int i=1;i<=m; ++i){
        for(int j=1; j<=n; ++j){
            path_cost[i][j]=cost[i][j]+min(path_cost[i-1][j-1], path_cost[i-1][j],path_cost[i][j-1]);
        }
    }

    print_array2d(&path_cost[0][0], m+1, n+1);

    return path_cost[m][n];
}

 
/* Driver program to test above functions */
int main()
{
   int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   printf(" %d ", minCost(cost, 2, 2));
   return 0;
}