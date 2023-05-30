package com.company.trees.createBinaryTree;

public class BT {
    public Node root;

    public BT(int data) {
        this.root = new Node(data);
    }

    public BT() {
        this.root = null;
    }

    public void printAllRootToLeafPaths(Node node, String path) {
        if (node == null) {
            return;
        }
        if (node.left == null && node.right == null) {
            System.out.println(path + node.data);
            return;
        }
        printAllRootToLeafPaths(node.left, path + node.data + "->");
        printAllRootToLeafPaths(node.right, path + node.data + "->");
    }

    public void printSpecificRootToLeafPaths(Node node, String path, int sum, int lo, int hi) {
        if (node == null) {
            return;
        }
        if (node.left == null && node.right == null) {
            sum += node.data;
            if (sum > lo && sum < hi) {
                System.out.println(path + node.data);
            }
            return;
        }
        printSpecificRootToLeafPaths(node.left, path + node.data + "->", sum + node.data, lo, hi);
        printSpecificRootToLeafPaths(node.right, path + node.data + "->", sum + node.data, lo, hi);
    }
}
