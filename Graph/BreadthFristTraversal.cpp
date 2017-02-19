// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include<iostream>
#include <list>
#include <queue>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void BFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
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

void Graph::BFSUtil(int v, bool visited[]){
    queue<int> gque;
    gque.push(v);

    while(!gque.empty()){

        int i=gque.front();
        gque.pop();
        cout<<i<<" ";
        visited[i]=true;

        // list<int>::iterator j;
        for(auto j=adj[i].begin(); j!=adj[i].end(); ++j){
            if(!visited[*j])
                gque.push(*j);
        }
    }

}
 
void Graph::BFS(int s)
{
    bool * visited= new bool[V];
    for(int i=0; i<V; ++i){
        visited[i]=false;
    }

    BFSUtil(s, visited);

    for(int i=0; i<V; ++i){
        if(!visited[i])
            BFSUtil(i,visited);
    }

    delete[] visited;
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(5);
 
    return 0;
}