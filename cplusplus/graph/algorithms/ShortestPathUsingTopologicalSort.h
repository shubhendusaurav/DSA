// Program to find the shortest path in directed acyclic graphs using topological sort.
 
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits.h>
 
using namespace std;
 
class WeightedGraph
{
    private:
        int vertexCount, edgeCount;
        unordered_map<int, vector<vector<int>>> adjacencyList;
 
        void updateDistance(vector<int> edge, int source, unordered_map<int, int> &distance);
    public:
        WeightedGraph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int weight, bool isDirected);
        void printAdjacencyList();
        void applyDFS(int node, unordered_map<int, bool> &visited, stack<int> &sortedGraph);
        stack<int> findTopologicalOrder(int sourceNode);
        void findShortestPath(int source, stack<int> &sortedGraph);
};
 
WeightedGraph::WeightedGraph(int vertexCount, int edgeCount)
{
    this->vertexCount = vertexCount;
    this->edgeCount = edgeCount;
}
 
void WeightedGraph::addEdge(int sourceNode, int destinationNode, int weight, bool isDirected)
{
    vector<int> edge;
    edge.push_back(destinationNode);
    edge.push_back(weight);
    adjacencyList[sourceNode].push_back(edge);
    if (!isDirected)
    {
        vector<int> reverseEdge;
        reverseEdge.push_back(sourceNode);
        reverseEdge.push_back(weight);
        adjacencyList[destinationNode].push_back(reverseEdge);
    }
}
 
void WeightedGraph::printAdjacencyList()
{
    for (auto i : this->adjacencyList)
    {
        cout<<i.first<<" -> ";
        for (auto j : i.second)
        {
            cout<<"["<<j[0]<<", "<<j[1]<<"] ";
        }
        cout<<endl;
    }
}
 
void WeightedGraph::applyDFS(int node, unordered_map<int, bool> &visited, stack<int> &sortedGraph)
{
    visited[node] = true;
 
    for (auto edge : this->adjacencyList[node])
    {
        if (!visited[edge[0]])
        {
            this->applyDFS(edge[0], visited, sortedGraph);
        }
    }
 
    sortedGraph.push(node);
}
 
stack<int> WeightedGraph::findTopologicalOrder(int sourceNode)
{
    stack<int> sortedGraph;
    unordered_map<int, bool> visited;
    this->applyDFS(sourceNode, visited, sortedGraph);
    return sortedGraph;
}
 
void WeightedGraph::findShortestPath(int source, stack<int> &sortedGraph)
{
    unordered_map<int, int> distance;
    for (auto row : this->adjacencyList)
    {
        distance[row.first] = INT_MAX;
        for (auto edge : row.second)
        {
            distance[edge[0]] = INT_MAX;
        }
    }
 
    distance[source] = 0;
 
    while (!sortedGraph.empty())
    {
        int topNode = sortedGraph.top();
        sortedGraph.pop();
 
        if (distance[topNode] != INT_MAX)
        {
            for (auto edge : this->adjacencyList[topNode])
            {
                updateDistance(edge, topNode, distance);
            }
        }
    }
 
    for (auto dist : distance)
    {
        cout<<dist.first<<" -> "<<dist.second<<endl;
    }
}
 
void WeightedGraph::updateDistance(vector<int> edge, int source, unordered_map<int, int> &distance)
{
    int node = edge[0];
    int weight = edge[1];
    if (distance[node] > weight + distance[source])
    {
        distance[node] = weight + distance[source];
    }
}
 
int main()
{
    WeightedGraph graph(6, 9);
    graph.addEdge(0, 1, 5, 1);
    graph.addEdge(0, 2, 3, 1);
    graph.addEdge(1, 3, 6, 1);
    graph.addEdge(1, 2, 2, 1);
    graph.addEdge(2, 3, 7, 1);
    graph.addEdge(2, 4, 4, 1);
    graph.addEdge(3, 4, -1, 1);
    graph.addEdge(2, 5, 2, 1);
    graph.addEdge(4, 5, -2, 1);
 
    // graph.printAdjacencyList();
    stack<int> sortedGraph = graph.findTopologicalOrder(0);
    graph.findShortestPath(1, sortedGraph);
    // while (!sortedGraph.empty())
    // {
    //     cout<<sortedGraph.top()<<" ";
    //     sortedGraph.pop();
    // }
 
    return 0;
}