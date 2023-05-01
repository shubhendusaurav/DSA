#include <iostream>
#include <vector>
 
using namespace std;
 
class Graph
{
    private:
        vector<vector<int>> edges;
        int vertexCount;
        int edgeCount;
    public:
        Graph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int weight);
        int applyBellmanFord(int source, int destination);
};
 
Graph::Graph(int vertexCount, int edgeCount)
{
    this->vertexCount = vertexCount;
    this->edgeCount = edgeCount;
}
 
void Graph::addEdge(int sourceNode, int destinationNode, int weight)
{
    vector<int> v1;
    v1.push_back(sourceNode);
    v1.push_back(destinationNode);
    v1.push_back(weight);
    this->edges.push_back(v1);
}
 
int Graph::applyBellmanFord(int source, int destination)
{
    vector<int> dist(this->vertexCount+1, 1e9);
    dist[source] = 0;
 
    for (int i=1; i<=this->vertexCount-1; ++i)
    {
        for (int j=0; j<this->edgeCount; ++j)
        {
            int sourceNode = this->edges[j][0];
            int destinationNode = this->edges[j][1];
            int weight = this->edges[j][2];
            if (dist[sourceNode] + weight < dist[destinationNode])
            {
                dist[destinationNode] = dist[sourceNode] + weight;
            }
        }
    }
 
    bool flag = false;
 
    for (int j=0; j<this->edgeCount; ++j)
    {
        int sourceNode = edges[j][0];
        int destinationNode = edges[j][1];
        int weight = edges[j][2];
        if (dist[sourceNode] + weight < dist[destinationNode])
        {
            flag = true;
            break;
        }
    }
 
    if (flag)
    {
        return -1;
    }
 
    return dist[destination];
}
 
int main()
{
    Graph g(3, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, -1);
    g.addEdge(1, 3, 2);
 
    int distance = g.applyBellmanFord(1, 3);
 
    if (distance == -1)
    {
        cout<<"Negative cycle found."<<endl;
    } else {
        cout<<distance<<endl;
    }
 
    return 0;
}