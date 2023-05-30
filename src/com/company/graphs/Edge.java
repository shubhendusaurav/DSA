package com.company.graphs;

import java.security.spec.EdDSAParameterSpec;

public class Edge {
    public int src;
    public int nbr;
    public int weight;

    public Edge(int src, int nbr, int weight){
        this.src = src;
        this.nbr = nbr;
        this.weight = weight;
    }
}
