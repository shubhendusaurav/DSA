// C++ code to detect cyclic graph using BFS and DFS

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
		unordered_map<int, int> parent;
		
		void markVisited(int node);
		int processNeighbours(list<int> &queue, int frontNode);
		
	public:
		Graph(int vertexCount);
		void addEdge(int sourceNode, int destinationNode, bool isDirectedGraph);
		int isCyclicBFS(int sourceNode);
		int isCyclicDFS(int sourceNode, int parentNode);
};

void Graph::markVisited(int node)
{
	this->visited[node] = true;
}

int Graph::processNeighbours(list<int> &queue, int frontNode)
{
	for (auto node: adjacencyList[frontNode])
	{
	    if (this->visited[node] && node != this->parent[frontNode])
	    {
	        return 1;
	    }
	    else if (!this->visited[node])
		{
			markVisited(node);
			this->parent[node] = frontNode;
			queue.push_back(node);
		}
	}
	
	return 0;
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

int Graph::isCyclicBFS(int sourceNode)
{
    list<int> queue;
    this->visited[sourceNode] = true;
    this->parent[sourceNode] = -1;
    int result = 0;
    
    queue.push_back(sourceNode);
    
    while (!queue.empty())
    {
        int frontNode = queue.front();
        queue.pop_front();
        result = processNeighbours(queue, frontNode);
        if (result == 1)
        {
            break;
        }
    }
    
    return result;
}

int Graph::isCyclicDFS(int node, int parentNode)
{
    list<int> queue;
    this->visited[node] = true;
    this->parent[node] = parentNode;
	
	for (list<int>::iterator i=adjacencyList[node].begin(); i!=adjacencyList[node].end(); ++i)
	{
		if (!this->visited[*i])
		{
			int result = isCyclicDFS(*i, node);
			if (result == 1)
			{
			    return result;
			}
		}
		else if (this->parent[node] != (*i))
		{
			return 1;
		}
	}
    
    return 0;
}

int main()
{
	Graph graph(6);
	graph.addEdge(0, 1, 0);
	graph.addEdge(1, 2, 0);
	graph.addEdge(1, 3, 0);
	graph.addEdge(2, 4, 0);
	graph.addEdge(3, 4, 0);
	graph.addEdge(4, 5, 0);
	
	cout<<"Cycle detection using BFS in undirected graph: "<<endl;
	int result = graph.isCyclicBFS(0);
	
	if (result == 1)
    {
        cout<<"The graph is cyclic."<<endl;
    }
	else
	{
	     cout<<"The graph is acyclic."<<endl;
	}
	
	Graph graph1(6);
	graph1.addEdge(0, 1, 0);
	graph1.addEdge(1, 2, 0);
	graph1.addEdge(1, 3, 0);
	graph1.addEdge(2, 4, 0);
// 	graph1.addEdge(3, 4, 0);
	graph1.addEdge(4, 5, 0);
	
	cout<<"Cycle detection using DFS in undirected graph: "<<endl;
	result = graph1.isCyclicDFS(0, -1);
	
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