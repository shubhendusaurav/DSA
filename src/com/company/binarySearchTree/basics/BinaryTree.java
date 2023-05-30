package com.company.binarySearchTree.basics;

import java.util.HashSet;

public class BinaryTree {
    Node root;

    BinaryTree() {
        this.root = null;
    }

    BinaryTree(Node root) {
        this.root = root;
    }

    public static int max(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }
        int lmax = max(node.left);
        int rmax = max(node.right);
        return Math.max(node.data, Math.max(lmax, rmax));
    }

    public static int min(Node node) {
        if (node == null) {
            return Integer.MAX_VALUE;
        }
        int lmin = min(node.left);
        int rmin = min(node.right);
        return Math.min(node.data, Math.min(lmin, rmin));
    }

    static HashSet<Integer> set = new HashSet<>();

    public boolean isBST(Node node) {
        if (node == null)
            return true;
        if (set.contains(node.data))
            return false;
        set.add(node.data);
        return isBST(node.left) && isBST(node.right) &&
                (node.data >= max(node.left) && node.data <= min(node.right));
    }

    public int height(Node node) {
        if (node == null) {
            return 0;
        }
        int lh = height(node.left);
        int rh = height(node.right);
        return Math.max(lh, rh) + 1;
    }

    public boolean isBalancedTree(Node node) {
        if (node == null)
            return true;
        int bal = Math.abs(height(node.left) - height(node.right));
        return bal <= 1;
    }

    class BSTPair{
        boolean isBSTPair;
        Node root;
        int size;
    }
//    public BSTPair isValidBST(Node node) {
//        if (node == null) {
//            BSTPair pair = new BSTPair();
//            pair.isBSTPair = true;
//            pair.size = 0;
//            return pair;
//        }
//        BSTPair pair = new BSTPair();
//        if (set.contains(node.data)) {
//            pair.isBSTPair = false;
//            return pair;
//        }
//        set.add(node.data);
//        return isBST(node.left) && isBST(node.right) &&
//                (node.data >= max(node.left) && node.data <= min(node.right));
//    }
}
