#include <iostream>
#include <list>
using namespace std;
 
// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
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

    cout<<v<<" ";
    visited[v]=true;

    list<int>::iterator i;

    for(i=adj[v].begin(); i!=adj[v].end(); ++i){
        if(!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int v){
    bool * visited= new bool[V];

    for(int i=0; i<V; ++i){
        visited[i]=false;
    }

    DFSUtil(v, visited);

    for(int i=0; i<V; ++i){
        if(!visited[i])
            DFSUtil(i,visited);
    }

    delete[] visited;

}
 

 
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(2, 0);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is Depth First Traversal (starting from vertex 5) \n";
    g.DFS(5);
 
    return 0;
}