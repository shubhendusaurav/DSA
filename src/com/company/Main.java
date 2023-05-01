package com.company;

import com.company.trees.createBinaryTree.BinaryTree;
import com.company.trees.createBinaryTree.Node;

import java.sql.Time;

public class Main {

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(23);
        tree.root.left = new Node(18);
        tree.root.right = new Node(54);
        tree.root.left.left = new Node(33);
        tree.root.left.right = new Node(19);
        tree.root.right.left = new Node(77);
        tree.root.left.right.left = new Node(89);

//        tree.inOrderTraversal();
//        tree.preOrderTraversal();
//        tree.postOrderTraversal();
        tree.levelOrderTraversal(); // RPA - Queue

        /*Size, Sum, Max and Height in a Binary Tree*/
//        System.out.println("Size of Tree : " + tree.size(tree.root));
//        System.out.println("Sum of Tree : " + tree.sum(tree.root));
//        System.out.println("Max of Tree : " + tree.max(tree.root));
//        System.out.println("Height of Tree : " + tree.height(tree.root));

        /*Find in tree AND NodeToRootPath*/
//        System.out.println("Node found : " + tree.find(tree.root, 9));
//        System.out.println("NodeToRootPath " + tree.getNodeToRootPath(tree.root, 89));

        /*Print k levels down*/
//        tree.printKLevelsDown(tree.root, 0);

        /*Convert BT to DLL such that the left pointer of the node should be pointing to the previous node
        in the doubly linked list, and the right pointer should be pointing to the next node in the doubly linked list
        Order of the nodes in the doubly linked list must be same as in the inorder traversal of Binary Tree*/

//        tree.inOrderTraversal();
        tree.createLinkedList();
        System.out.println("Converted to DLL");
        tree.printDLL();

    }
}
