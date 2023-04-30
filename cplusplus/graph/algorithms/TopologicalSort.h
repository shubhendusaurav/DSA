// Prog 1: Topological sort using DFS
// Prog 2: Topological sort using BFS - Kahn's algorithm
// Prog 3: Cycle detection using Kahn's algorithm
 
#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <queue>
 
using namespace std;
 
class Graph
{
    private:
        int vertexCount, edgeCount;
        unordered_map<int, list<int>> adjacencyList;
        unordered_map<int, bool> visited;
        stack<int> answer;
    public:
        Graph(int vertexCount, int edgeCount);
        void addEdge(int sourceNode, int destinationNode, int isDirected);
        void topologicalSortDFS(int sourceNode);
        void topologicalSortBFS(int sourceNode);
        void printSorted();
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
 
void Graph::topologicalSortDFS(int node)
{
    this->visited[node] = true;
 
    for (list<int>::iterator i=adjacencyList[node].begin(); i != adjacencyList[node].end(); ++i)
    {
        if (!visited[*i])
        {
            topologicalSortDFS(*i);
        }
    }
 
    answer.push(node);
}
 
void Graph::topologicalSortBFS(int sourceNode)
{
    unordered_map<int, int> indegree;
    for (auto i:this->adjacencyList)
    {
        indegree[i.first] = 0;
    }
 
    for (auto i: this->adjacencyList)
    {
        for (auto j: i.second)
        {
            indegree[j]++;
        }
    }
 
    queue<int> queue;
    for (auto i: this->adjacencyList)
    {
        if (indegree[i.first] == 0)
        {
            queue.push(i.first);
        }
        for (auto j: i.second)
        {
            if (indegree[j] == 0)
            {
                queue.push(j);
            }
        }
    }
 
    vector<int> answer;
    int nodeCounter = 0;
    while (!queue.empty())
    {
        int front = queue.front();
        queue.pop();
        answer.push_back(front);
        nodeCounter++;
 
        for (auto neighbour: this->adjacencyList[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                queue.push(neighbour);
            }
        }
    }
 
    while (!answer.empty())
    {
        this->answer.push(answer.back());
        answer.pop_back();
    }
 
    if (nodeCounter != this->vertexCount)
    {
        cout<<"Cycle is present and hence cannot generate a valid topological sort.";
        while(this->answer.empty())
        {
            this->answer.pop();
        }
    }
}
 
void Graph::printSorted()
{
    while (!answer.empty())
    {
        cout<<answer.top()<<" ";
        answer.pop();
    }
}
 
int main()
{
    Graph graph(6, 7);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 1);
    graph.addEdge(4, 5, 1);
    graph.addEdge(4, 6, 1);
    graph.addEdge(5, 6, 1);
 
    graph.topologicalSortDFS(1);
    cout<<endl<<"After performing topological sort using DFS: ";
    graph.printSorted();
 
    Graph graph1(5, 5);
    graph1.addEdge(1, 2, 1);
    graph1.addEdge(1, 3, 1);
    graph1.addEdge(2, 5, 1);
    graph1.addEdge(3, 5, 1);
    graph1.addEdge(5, 4, 1);
 
    graph1.topologicalSortBFS(1);
    cout<<endl<<"After performing topological sort using BFS: ";
    graph1.printSorted();
 
    return 0;
}