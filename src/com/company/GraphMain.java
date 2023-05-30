package com.company;

import com.company.graphs.Edge;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class GraphMain {

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        int vtces = Integer.parseInt(br.readLine());
//        // Graph = Array of ArrayList of Edges
//        ArrayList<Edge>[] graph = new ArrayList[vtces];
//        for (int i = 0; i < vtces; i++) {
//            graph[i] = new ArrayList<>();
//        }
//        int edges = Integer.parseInt(br.readLine());
//        for (int i = 0; i < edges; i++) {
//            String[] parts = br.readLine().split(" ");
//            int v1 = Integer.parseInt(parts[0]);
//            int v2 = Integer.parseInt(parts[1]);
//            int wt = Integer.parseInt(parts[2]);
//            graph[v1].add(new Edge(v1, v2, wt));
//            graph[v2].add(new Edge(v2, v1, wt));
//        }
//        int src = Integer.parseInt(br.readLine());
//        int dest = Integer.parseInt(br.readLine());
        // check if there is a path between src and dest
//        System.out.println(src + " to " + dest + " path is available: " + hasPath(graph, src, dest, new boolean[vtces]));
//        printAllPaths(graph, src, dest, new boolean[vtces], src + " ");
//        multiSolver(graph, src, dest, 40, new boolean[vtces], src + " ", 0, 3);
//        System.out.println("Smallest Path: " + spath + "@" + spathwt);
//        System.out.println("Longest Path: " + lpath + "@" + lpathwt);
//        System.out.println("Ceiling Path: " + cpath + "@" + cpathwt);
//        System.out.println("Floor Path: " + fpath + "@" + fpathwt);
//        System.out.println("3rd Largest Path: " + pq.peek().path + "@" + pq.peek().sum);
//        BFS(graph, 2, new boolean[vtces]);
//        ArrayList<ArrayList<Integer>> comps = new ArrayList<>();
//        boolean[] visited = new boolean[vtces];
//        for (int i = 0; i < vtces; i++) {
//            if(visited[i] == false){
//                ArrayList<Integer> comp = new ArrayList<>();
//                getConnectedGraphs(graph, i, comp, visited);
//                comps.add(comp);
//            }
//        }
//        System.out.println(comps);
//        if(comps.size() == 1)
//            System.out.println("Connected Graph");
//        else
//            System.out.println("Disconnected Graph");

        //Count Number of Islands using graphs
//        int[][] arr = {{1, 1, 0, 0, 0},
//                {0, 1, 0, 0, 1},
//                {1, 0, 0, 1, 1},
//                {0, 0, 0, 0, 0},
//                {1, 0, 1, 0, 1}};
//
//        boolean[][] visited = new boolean[arr.length][arr[0].length];
//        int count = 0;
//        for (int i = 0; i < arr.length; i++) {
//            for (int j = 0; j < arr[i].length; j++) {
//                if (arr[i][j] == 1 && visited[i][j] == false) {
//                    connectedGraphs(arr, i, j, visited);
//                    count++;
//                }
//            }
//        }
//        System.out.println(count);
//        boolean[] visited = new boolean[vtces];
//        isCyclic(graph, 0, visited);
        int[][] i = new int[5][];
        System.out.println(10/0.0);
    }

    public static void connectedGraphs(int[][] arr, int i, int j, boolean[][] visited) {
        if (i < 0 || j < 0 || i >= arr.length || j >= arr[0].length || arr[i][j] == 0 || visited[i][j] == true) {
            return;
        }
        visited[i][j] = true;
        connectedGraphs(arr, i, j - 1, visited);
        connectedGraphs(arr, i - 1, j, visited);
        connectedGraphs(arr, i, j + 1, visited);
        connectedGraphs(arr, i + 1, j, visited);
        connectedGraphs(arr, i - 1, j - 1, visited);
        connectedGraphs(arr, i - 1, j + 1, visited);
        connectedGraphs(arr, i + 1, j + 1, visited);
        connectedGraphs(arr, i + 1, j - 1, visited);
    }

    public static boolean hasPath(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited) {
        if (src == dest)
            return true;
        visited[src] = true;
        for (Edge edge : graph[src]) {
            if (!visited[edge.nbr]) {
                boolean hasNbrPath = hasPath(graph, edge.nbr, dest, visited);
                return hasNbrPath;
            }
        }
        return false;
    }

    //BFS Breadth First Search - R M* W A*
    //Add the 1st element in Queue
    //R -> Remove from queue
    //Mark as visited
    //Work -> Print it
    //Add the neighbours

    static void BFS(ArrayList<Edge>[] graph, int src, boolean[] visited) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        while (queue.size() > 0) {
            src = queue.poll();
            if (visited[src])
                continue;
            visited[src] = true;
            System.out.print(src + " ");
            for (Edge edge : graph[src]) {
                queue.add(edge.nbr);
            }
        }
    }

    static void printAllPaths(ArrayList<Edge>[] graph, int src, int dest, boolean[] visited, String path) {
        if (src == dest) {
            System.out.println(path);
            return;
        }
        visited[src] = true;
        for (Edge edge : graph[src]) {
            if (!visited[edge.nbr])
                printAllPaths(graph, edge.nbr, dest, visited, path + edge.nbr + " ");
        }
        visited[src] = false;
    }

    static class Pair implements Comparable<Pair> {
        int sum;
        String path;

        Pair(int sum, String path) {
            this.sum = sum;
            this.path = path;
        }

        @Override
        public int compareTo(Pair p) {
            return this.sum - p.sum;
        }
    }

    //DFS - visited array
    //src == dest then stop
    // mark visited
    //loop through children
    //mark unvisited on way out
    static Integer spathwt = Integer.MAX_VALUE;
    static String spath;
    static Integer lpathwt = Integer.MIN_VALUE;
    static String lpath;
    static Integer cpathwt = Integer.MAX_VALUE;
    static String cpath;
    static Integer fpathwt = Integer.MIN_VALUE;
    static String fpath;
    static PriorityQueue<Pair> pq = new PriorityQueue<>();

    static void multiSolver(ArrayList<Edge>[] graph, int src, int dest, int criteria, boolean[] visited, String path, int totalSum, int k) {
        if (src == dest) {
            if (totalSum < spathwt) {
                spathwt = totalSum;
                spath = path;
            }
            if (totalSum > lpathwt) {
                lpathwt = totalSum;
                lpath = path;
            }
            if (totalSum > criteria && totalSum < cpathwt) {
                cpathwt = totalSum;
                cpath = path;
            }
            if (totalSum < criteria && totalSum > fpathwt) {
                fpathwt = totalSum;
                fpath = path;
            }
            if (pq.size() < k)
                pq.add(new Pair(totalSum, path));
            else {
                if (totalSum > pq.peek().sum) {
                    pq.remove();
                    pq.add(new Pair(totalSum, path));
                }
            }
            return;
        }
        visited[src] = true;
        for (Edge edge : graph[src]) {
            if (!visited[edge.nbr]) {
                multiSolver(graph, edge.nbr, dest, criteria, visited, path + edge.nbr + " ", totalSum + edge.weight, k);
            }
        }
        visited[src] = false;
    }

    static void getConnectedGraphs(ArrayList<Edge>[] graph, int src, ArrayList<Integer> comp, boolean[] visited) {
        visited[src] = true;
        comp.add(src);
        for (Edge edge : graph[src]) {
            if (visited[edge.nbr] == false) {
                getConnectedGraphs(graph, edge.nbr, comp, visited);
            }
        }
    }

    //rmwa
    static boolean isCyclic(ArrayList<Edge>[] graph, int src, boolean[] visited) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(src);
        while (queue.size() > 0) {
            src = queue.poll();
            if (visited[src])
                return true;
            visited[src] = true;
            for (Edge edge : graph[src]) {

                if (visited[edge.nbr] == false)
                    queue.add(edge.nbr);
            }
        }
        return false;
    }

}
