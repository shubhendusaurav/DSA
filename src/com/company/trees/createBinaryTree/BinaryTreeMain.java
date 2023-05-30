package com.company.trees.createBinaryTree;

public class BinaryTreeMain {

    public static void main(String[] args) {
        BT tree = new BT();
        tree.root = new Node(23);
        tree.root.left = new Node(18);
        tree.root.right = new Node(54);
        tree.root.left.left = new Node(33);
        tree.root.left.right = new Node(19);
        tree.root.right.left = new Node(77);
        tree.root.left.right.left = new Node(89);

//        tree.printAllRootToLeafPaths(tree.root, "");
        tree.printSpecificRootToLeafPaths(tree.root,"",0,100,200);
    }

}
