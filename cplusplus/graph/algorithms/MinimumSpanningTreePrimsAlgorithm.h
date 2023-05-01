// Program to find minimum spanning tree using Prim's algorithm


#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <limits.h>
 
using namespace std;
 
class WeightedGraph
{
    private:
        int vertexCount, edgeCount;
        unordered_map<int, vector<vector<int>>> adjacencyList;
        void initializeVertexList(set<int> &vertexList);
 
    public:
        WeightedGraph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int weight, bool isDirected);
        void printAdjacencyList();
        vector<pair<pair<int, int>, int>> findMinimumSpanningTree(int sourceNode);
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
 
void WeightedGraph::initializeVertexList(set<int> &vertices)
{
    for (auto row : this->adjacencyList)
    {
        vertices.insert(row.first);
        for (auto edge : row.second)
        {
            vertices.insert(edge[0]);
        }
    }
}
 
vector<pair<pair<int, int>, int>> WeightedGraph::findMinimumSpanningTree(int sourceNode)
{
    unordered_map<int, int> key;
    unordered_map<int, bool> mst;
    unordered_map<int, int> parent;
    set<int> vertices;
 
    initializeVertexList(vertices);
 
    for (auto vertex : vertices)
    {
        key[vertex] = INT_MAX;
        mst[vertex] = false;
        parent[vertex] = -1;
    }
 
    key[sourceNode] = 0;
 
    for (int vertex : vertices)
    {
        int minimumKeyValue = INT_MAX;
        int minVertex;
 
        // Find minimum value
        for (auto currentVertex : vertices)
        {
            if (mst[currentVertex] == false && key[currentVertex] < minimumKeyValue)
            {
                minVertex = vertex;
                minimumKeyValue = key[currentVertex];
            }
        }
 
        // Set included in mst to be true
        mst[minVertex] = true;
 
        // find adjacent and update key and parent, if needed 
        for (auto edge : this->adjacencyList[minVertex])
        {
            int neighbour = edge[0];
            int weight = edge[1];
            if (mst[neighbour] == false && weight < key[neighbour])
            {
                key[neighbour] = weight;
                parent[neighbour] = minVertex;
            }
        }
    }
 
    vector<pair<pair<int, int>, int>> result;
    for (auto vertex : vertices)
    {
        result.push_back({{parent[vertex], vertex}, key[vertex]});
    }
 
    return result;
}
 
int main()
{
    WeightedGraph graph(5, 6);
    graph.addEdge(0, 1, 2, 0);
    graph.addEdge(0, 3, 6, 0);
    graph.addEdge(1, 2, 3, 0);
    graph.addEdge(1, 4, 5, 0);
    graph.addEdge(1, 3, 8, 0);
    graph.addEdge(2, 4, 7, 0);
 
    // graph.printAdjacencyList();
    auto result = graph.findMinimumSpanningTree(0);
 
    int totalWeight = 0;
 
    for (auto pair : result)
    {
        cout<<pair.first.first<<" is parent node for "<<pair.first.second<<" with weight "<<pair.second<<endl;
        totalWeight += pair.second;
    }
 
    cout<<endl<<"Weight of minimum spanning tree: "<<totalWeight<<endl;
    return 0;
}