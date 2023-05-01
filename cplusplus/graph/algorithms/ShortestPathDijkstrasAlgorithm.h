// Program to find the shortest path using Dijkstra's Algorithm

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <limits.h>
 
using namespace std;
 
class WeightedGraph
{
    private:
        int vertexCount, edgeCount;
        unordered_map<int, vector<vector<int>>> adjacencyList;
 
    public:
        WeightedGraph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int weight, bool isDirected);
        void printAdjacencyList();
        void dijkstraShortestPath(int sourceNode);
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
 
void WeightedGraph::dijkstraShortestPath(int sourceNode)
{
    unordered_map<int, int> distance;
    set<pair<int, int>> processor;
 
    for (auto row : this->adjacencyList)
    {
        distance[row.first] = INT_MAX;
        for (auto edge : row.second)
        {
            distance[edge[0]] = INT_MAX;
        }
    }
 
    distance[sourceNode] = 0;
    processor.insert(make_pair(0, sourceNode));
 
    while (!processor.empty())
    {
        auto topNode = *(processor.begin());
        int nodeDistance = topNode.first;
        int nodeValue = topNode.second;
 
        processor.erase(processor.begin());
 
        for (auto edge : this->adjacencyList[nodeValue])
        {
            int neighbour = edge[0];
            int weight = edge[1];
            if (weight + nodeDistance < distance[neighbour])
            {
                auto record = processor.find(make_pair(distance[neighbour], neighbour));
                if (record != processor.end())
                {
                    processor.erase(record);
                }
 
                distance[neighbour] = weight + nodeDistance;
                processor.insert(make_pair(distance[neighbour], neighbour));
            }
        }
    }
 
    for (auto dist : distance)
    {
        cout<<dist.first<<" "<<dist.second<<endl;
    }
}
 
int main()
{
    WeightedGraph graph(5, 7);
    graph.addEdge(0, 3, 2, 0);
    graph.addEdge(1, 0, 7, 0);
    graph.addEdge(1, 2, 3, 0);
    graph.addEdge(1, 3, 5, 0);
    graph.addEdge(1, 4, 1, 0);
    graph.addEdge(2, 0, 1, 0);
    graph.addEdge(3, 4, 7, 0);
 
    // graph.printAdjacencyList();
    graph.dijkstraShortestPath(0);
 
    return 0;
}