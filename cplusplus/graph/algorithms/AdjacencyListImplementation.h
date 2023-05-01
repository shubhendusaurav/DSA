#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{
    public:
        unordered_map<int, list<int>> adjacencyList;
        
        void addEdge(int sourceNode, int destinationNode, bool isDirectedGraph)
        {
        	adjacencyList[sourceNode].push_back(destinationNode);
        	if (isDirectedGraph == false)
        	{
        	    adjacencyList[destinationNode].push_back(sourceNode);
        	}
        }
        
        void displayAdjacencyList()
        {
        	for (auto i:adjacencyList)
        	{
        		cout<<i.first<<" -> ";
        		for(int j:i.second)
        		{
        			cout<<j<<" ";
        		}
        		cout<<endl;
        	}
        }
};

int main()
{
    Graph g;
    
	int vertexCount, edgeCount;
	cout<<"Enter number of vertices: ";
	cin>>vertexCount;
	cout<<"Enter number of edges: ";
 	cin>>edgeCount;

	for (int i=0; i<edgeCount; i++)
	{
		int node1, node2;
		cout<<"Enter nodes seperated with a space: ";
		cin>>node1>>node2;
		g.addEdge(node1, node2, false);
	}
	
	g.displayAdjacencyList();
	
	return 0;
}