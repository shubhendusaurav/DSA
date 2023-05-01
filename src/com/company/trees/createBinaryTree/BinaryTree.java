package com.company.trees.createBinaryTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {

    public Node root;

    public BinaryTree(int data) {
        this.root = new Node(data);
    }

    public BinaryTree() {
        this.root = null;
    }

    public void inOrderTraversal() {
        inOrder(root);
    }

    public void preOrderTraversal() {
        preOrder(root);
    }

    public void postOrderTraversal() {
        postOrder(root);
    }

    public void levelOrderTraversal() {
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        while (queue.size() > 0) {
            int count = queue.size();
            for (int i = 0; i < count; i++) {
                Node node = queue.remove();
                System.out.print(node.data + " ");
                if (node.left != null)
                    queue.add(node.left);
                if (node.right != null)
                    queue.add(node.right);
            }
            System.out.println();
        }
    }

    public void inOrder(Node node) {
        if (node != null) {
            inOrder(node.left);
            System.out.println(node.data);
            inOrder(node.right);
        }
    }

    public void preOrder(Node node) {
        if (node != null) {
            System.out.println(node.data);
            preOrder(node.left);
            preOrder(node.right);
        }
    }

    public void postOrder(Node node) {
        if (node != null) {
            postOrder(node.left);
            postOrder(node.right);
            System.out.println(node.data);
        }
    }

    public void createLinkedList() {
        createLinkedListHelper(root);
    }

    static int flag = 0;
    static Node parent = null;
    static Node head = null;

    public void createLinkedListHelper(Node node) {
        if (node != null) {
            createLinkedListHelper(node.left);
            if (flag == 0) {
                head = node; // help printDLL
                parent = node;
                flag = 1;
            } else {
                parent.right = node;
                node.left = parent;
                parent = node;
            }
            createLinkedListHelper(node.right);
        }
    }

    public void printDLL() {
        Node node = head;
        while (node != null) {
            System.out.println(node.data);
            node = node.right;
        }
    }

    public int size(Node node) {
        if (node == null) {
            return 0;
        }
        int ls = size(node.left);
        int rs = size(node.right);
        int ts = ls + rs + 1;
        return ts;
    }

    public int sum(Node node) {
        if (node == null) {
            return 0;
        }
        int ls = sum(node.left);
        int rs = sum(node.right);
        int ts = ls + rs + node.data;
        return ts;
    }

    public int max(Node node) {
        if (node == null)
            return Integer.MIN_VALUE;
        int lm = max(node.left);
        int rm = max(node.right);
        int tm = Math.max(node.data, Math.max(lm, rm));
        return tm;
    }

    public int height(Node node) {
        if (node == null)
            return -1; // -1 edges, 0 nodes
        int lh = height(node.left);
        int rh = height(node.right);
        int th = Math.max(lh, rh) + 1;
        return th;
    }

    static ArrayList<Integer> nodeToRootPath;

    public boolean find(Node node, int data) {
        if (node == null)
            return false;
        if (node.data == data) {
            nodeToRootPath.add(node.data);
            return true;
        }
        if (find(node.left, data)) {
            nodeToRootPath.add(node.data);
            return true;
        }
        if (find(node.right, data)) {
            nodeToRootPath.add(node.data);
            return true;
        }
        return false;
    }

    public ArrayList<Integer> getNodeToRootPath(Node node, int data) {
        nodeToRootPath = new ArrayList<>();
        find(node, data);
        return nodeToRootPath;
    }

    public void printKLevelsDown(Node node, int k) {
        if (node == null || k < 0) {
            return;
        }
        if (k == 0) {
            System.out.print(node.data + " ");
        }
        printKLevelsDown(node.left, k - 1);
        printKLevelsDown(node.right, k - 1);
    }
}
