import java.util.HashMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.Scanner;

public class Graph {

	Map<Integer, LinkedList<Integer>> adjacencyList;
	
	public Graph(int vertexCount) {
		initializeAdjacencyList(vertexCount);
	}
	
	public void initializeAdjacencyList(int vertexCount) {
		adjacencyList = new HashMap<Integer, LinkedList<Integer>>();
		for(int i=1; i<=vertexCount; ++i) {
			adjacencyList.put(i, new LinkedList<Integer>());
		}
	}
	
	public void addEdge(int sourceNode, int destinationNode, Boolean isDirectedGraph) {
		LinkedList sourceNeighbourList = adjacencyList.get(sourceNode);
		sourceNeighbourList.add(destinationNode);
		if (isDirectedGraph.equals(false)) {
			LinkedList destinationNeighbourList = adjacencyList.get(destinationNode);
			destinationNeighbourList.add(sourceNode);
		}
		
	}
	
	public void printAdjacencyList() {
		for (Map.Entry<Integer,LinkedList<Integer>> entry : adjacencyList.entrySet()) {
			Integer vertex = entry.getKey();
			LinkedList<Integer> neighbours = entry.getValue();
			
			System.out.print(vertex + " -> ");
			
			for (Integer neighbour : neighbours) {
				System.out.print(neighbour + " ");
			}
			
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Integer vertexCount, edgeCount;
		System.out.println("Enter number of vertices: ");
		vertexCount = Integer.parseInt(sc.nextLine());
		System.out.println("Enter number of edges: ");
		edgeCount = Integer.parseInt(sc.nextLine());
		
		Graph graph = new Graph(vertexCount);
		
		System.out.println("Enter the edges in the graph : <sourceNode> <destinationNode>");
		Integer sourceNode, destinationNode;
		for (int i=0; i<vertexCount; ++i) {
			sourceNode = sc.nextInt();
			destinationNode = sc.nextInt();
			graph.addEdge(sourceNode, destinationNode, false);
		}
		
		graph.printAdjacencyList();
	}
}