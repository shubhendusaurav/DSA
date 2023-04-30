// C++ code to print BFS and DFS traversal from a given source vertex for an undirected graph

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
	private:
		int vertexCount;
		vector<list<int>> adjacencyList;
		vector<bool> visited;
		
		void markVisited(vector<bool> &visited, int node);
		void processNode(int node);
		void processNeighbours(list<int> &queue, vector<bool> &visited, int frontNode);
		
	public:
		Graph(int vertexCount);
		void addEdge(int sourceNode, int destinationNode, bool isDirectedGraph);
		void traverseBFS(int sourceNode);
		void traverseDFS(int sourceNode);
};

void Graph::markVisited(vector<bool> &visited, int node)
{
	visited[node] = true;
}

void Graph::processNeighbours(list<int> &queue, vector<bool> &visited, int frontNode)
{
	for (auto node: adjacencyList[frontNode])
	{
		if (!visited[node])
		{
			markVisited(visited, node);
			queue.push_back(node);
		}
	}
}

void Graph::processNode(int node)
{
	cout<<node<<" ";
}

Graph::Graph(int vertexCount)
{
	this->vertexCount = vertexCount;
	visited.resize(this->vertexCount, false);
	adjacencyList.resize(vertexCount);
}

void Graph::addEdge(int sourceNode, int destinationNode, bool isDirectedGraph)
{
	this->adjacencyList[sourceNode].push_back(destinationNode);
	if (!isDirectedGraph)
	{
		this->adjacencyList[destinationNode].push_back(sourceNode);
	}
}

void Graph::traverseBFS(int sourceNode)
{
	list<int> queue;
	visited[sourceNode] = true;
	queue.push_back(sourceNode);
	
	while (!queue.empty())
	{
		int frontNode = queue.front();
		processNode(frontNode);
		queue.pop_front();
		processNeighbours(queue, visited, frontNode);
	}
}

void Graph::traverseDFS(int node)
{	
	visited[node] = true;
	processNode(node);
	
	for (list<int>::iterator i=adjacencyList[node].begin(); i!=adjacencyList[node].end(); ++i)
	{
		if (!visited[*i])
		{
			traverseDFS(*i);
		}
	}
}

int main()
{
	Graph graph(4);
	graph.addEdge(0, 1, 1);
	graph.addEdge(0, 2, 1);
	graph.addEdge(1, 2, 1);
	graph.addEdge(2, 0, 1);
	graph.addEdge(2, 3, 1);
	graph.addEdge(3, 3, 1);
	
	cout<<"BFS traversal for the above graph is as follows: "<<endl;
	graph.traverseBFS(2);
	
	Graph graph1(4);
	graph1.addEdge(0, 1, 1);
	graph1.addEdge(0, 2, 1);
	graph1.addEdge(1, 2, 1);
	graph1.addEdge(2, 0, 1);
	graph1.addEdge(2, 3, 1);
	graph1.addEdge(3, 3, 1);
	
	cout<<endl<<"DFS traversal for the above graph is as follows: "<<endl;
	graph1.traverseDFS(2);
	
	return 0;
}