package com.company.binarySearchTree.basics;

public class Main {

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(50);
        tree.root.left = new Node(25);
        tree.root.left.left = new Node(12);
        tree.root.left.right = new Node(37);
        tree.root.right = new Node(75);
        tree.root.right.left = new Node(62);
        tree.root.right.right = new Node(87);
        tree.root.right.left.left = new Node(60);
        tree.root.right.left.right = new Node(76);
        tree.root.right.left.left.left = new Node(66);

//        System.out.println(tree.isBST(tree.root));
        System.out.println(tree.isBalancedTree(tree.root));

    }
}
