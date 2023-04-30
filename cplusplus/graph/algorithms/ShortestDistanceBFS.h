// Prog 1: Topological sort using DFS
// Prog 2: Topological sort using BFS - Kahn's algorithm
// Prog 3: Cycle detection using Kahn's algorithm
 
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
 
using namespace std;
 
class Graph
{
    private:
        int vertexCount, edgeCount;
        unordered_map<int, list<int>> adjacencyList;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
    public:
        Graph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int isDirected);
        void findShortestPathBFS(int source, int destination);
};
 
Graph::Graph(int vertexCount, int edgeCount)
{
    this->vertexCount = vertexCount;
    this->edgeCount = edgeCount;
}
 
void Graph::addEdge(int sourceNode, int destinationNode, int isDirected)
{
    this->adjacencyList[sourceNode].push_back(destinationNode);
    if (!isDirected)
    {
        this->adjacencyList[destinationNode].push_back(sourceNode);
    }
}
 
void Graph::findShortestPathBFS(int source, int destination)
{
    queue<int> processor;
 
    this->visited[source] = true;
    this->parent[source] = -1;
    processor.push(source);
 
    while (!processor.empty())
    {
        int frontNode = processor.front();
        processor.pop();
        for (auto i : this->adjacencyList[frontNode])
        {
            if (!this->visited[i])
            {
                this->visited[i] = true;
                this->parent[i] = frontNode;
                processor.push(i);
            }
        }
    }
 
    while (destination != source)
    {
        cout<<destination<<" ";
        destination = parent[destination];
    }
    cout<<destination;
}
 
int main()
{
    Graph graph(8, 9);
    graph.addEdge(1, 2, 0);
    graph.addEdge(1, 3, 0);
    graph.addEdge(1, 4, 0);
    graph.addEdge(2, 5, 0);
    graph.addEdge(3, 8, 0);
    graph.addEdge(4, 6, 0);
    graph.addEdge(5, 8, 0);
    graph.addEdge(6, 7, 0);
    graph.addEdge(7, 8, 0);
 
    graph.findShortestPathBFS(1, 8);
 
    return 0;
}