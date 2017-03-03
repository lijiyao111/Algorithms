// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <stack>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void DFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[]){
    stack<int> gstack;
    gstack.push(v);
    // visited[v]=true;  

    while(!gstack.empty()){

        int i=gstack.top();
        gstack.pop();
        if(!visited[i]){
            cout<<i<<" ";
            visited[i]=true;   
        }
             
        

        // list<int>::iterator j;
        for(auto j=adj[i].begin(); j!=adj[i].end(); ++j){
            gstack.push(*j);
            if(!visited[*j]){
                gstack.push(*j);
            }

        }
    }

}
 
void Graph::DFS(int s)
{
    bool * visited= new bool[V];
    for(int i=0; i<V; ++i){
        visited[i]=false;
    }

    DFSUtil(s, visited);

    for(int i=0; i<V; ++i){
        if(!visited[i])
            DFSUtil(i,visited);
    }

    delete[] visited;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is Depth First Traversal "
         << "(starting from vertex 5) \n";
    g.DFS(5);
 
    return 0;
}