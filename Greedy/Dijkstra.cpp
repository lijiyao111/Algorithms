#include <stdio.h>
#include <cstring>
#include <limits.h>
#include "../array_utils.h"
  
// Number of vertices in the graph
#define V 9
// const bool True=1, False=0; // just use true, false
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[])
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}

int countSet(bool sptSet[]){
  int count=0;
  for(int i=0; i<V; ++i){
    if(sptSet[i]==true)
      count++;
  }
  return count;
}

void dijkstra(int graph[V][V],int s){
  int dist[V];
  bool sptSet[V];

  for(int i=0; i<V; ++i){
    dist[i]=INT_MAX;
    sptSet[i]=false;
  }


  dist[s]=0;
  sptSet[s]=true;
  for(int i=0; i<V; ++i){
    if(graph[s][i]!=0)
      dist[i]=graph[s][i];
  }
  // JL::print_array1d(dist,V);
  // JL::print_array1d(sptSet,V);

  while(countSet(sptSet)<V){
    int idx=minDistance(dist, sptSet);
    sptSet[idx]=true;
    for(int i=0; i<V; ++i){
      if(graph[idx][i]!=0)
        if(dist[i]>dist[idx]+graph[idx][i])
          dist[i]=dist[idx]+graph[idx][i];
    }
  }

  JL::print_array1d(dist,V);
  JL::print_array1d(sptSet,V);

  printSolution(dist);
}
  

  
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}