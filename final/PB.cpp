#include<iostream>
#include <list>
using namespace std;
 
 bool ans = true;
// This class represents a directed graph using adjacency list
// representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    bool isReachable(int s, int d, int dan); 
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
 
// A BFS based function to check whether d is reachable from s.
bool Graph::isReachable(int s, int d, int dan)
{
    // Base case
    if (s == d)
      return true;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then
            // return true
            if (*i == d)
                return true;
 
            // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                if (*i == dan){
                    ans = false;
                }
                queue.push_back(*i);
            }
        }
    }
     
    // If BFS is complete without visiting d
    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    int n, m, b;
    cin >> n >> m>>b;
    int u = 3, v = 0;
    // Create a graph given in the above diagram
    Graph g(n);
    int a, bb;
    for(int i = 0; i < m + 1; i++){
        cin >> a >> bb;
        if(i == 0){
            u = a - 1, v = bb - 1;
        }
        else
            g.addEdge(a-1, bb-1);
    }
    // g.addEdge(3, 0);
    // g.addEdge(0, 1);
    // g.addEdge(4, 2);
    // g.addEdge(0, 4);
    // g.addEdge(3, 2);
    // g.addEdge(1, 0);
    // g.addEdge(3, 4);
int t;
    if(b == 1){
        cin >> t;
    }
    if(g.isReachable(u, v, b - 1) && ans == true)
        cout<< "SAFE";
    else
        cout<< "UNSAFE";
 
   
 
    return 0;
}