// C++ code to detect cyclic graph using BFS and DFS in directed graphs

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Graph
{
	private:
		int vertexCount;
		unordered_map<int, list<int>> adjacencyList;
		unordered_map<int, bool> visited;
		unordered_map<int, bool> dfsVisited;
		
		void markVisited(int node);
		
	public:
		Graph(int vertexCount);
		void addEdge(int sourceNode, int destinationNode, bool isDirectedGraph);
		int isCyclicDFS(int sourceNode);
};

void Graph::markVisited(int node)
{
	this->visited[node] = true;
}

Graph::Graph(int vertexCount)
{
	this->vertexCount = vertexCount;
}

void Graph::addEdge(int sourceNode, int destinationNode, bool isDirectedGraph)
{
	this->adjacencyList[sourceNode].push_back(destinationNode);
	if (!isDirectedGraph)
	{
		this->adjacencyList[destinationNode].push_back(sourceNode);
	}
}

int Graph::isCyclicDFS(int node)
{
    list<int> queue;
    this->visited[node] = true;
    this->dfsVisited[node] = true;
	
	for (list<int>::iterator i=adjacencyList[node].begin(); i!=adjacencyList[node].end(); ++i)
	{
		if (!this->visited[*i])
		{
			int result = isCyclicDFS(*i);
			if (result == 1)
			{
			    return result;
			}
		}
		else if (this->dfsVisited[*i])
		{
			return 1;
		}
	}
    
	this->dfsVisited[node] = false;
    return 0;
}

int main()
{
	Graph graph1(6);
	graph1.addEdge(0, 1, 1);
	graph1.addEdge(1, 2, 1);
	graph1.addEdge(1, 3, 1);
	graph1.addEdge(2, 4, 1);
	graph1.addEdge(3, 4, 1);
// 	graph1.addEdge(4, 3, 1);
	graph1.addEdge(4, 5, 1);
	
	cout<<"Cycle detection using DFS in directed graph: "<<endl;
	int result = graph1.isCyclicDFS(0);
	
	if (result == 1)
    {
        cout<<"The graph is cyclic."<<endl;
    }
	else
	{
	     cout<<"The graph is acyclic."<<endl;
	}
	
	return 0;
}