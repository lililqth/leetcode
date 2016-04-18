package com.helloqiji;

/**
 * Created by qiji on 4/18/16.
 */
class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
     }

class Solution {
    int sum;
    Solution (){
        this.sum = 0;
    }
    int leftHeight(TreeNode root){
        TreeNode currentNode = root;
        int height;
        for (height = 0;currentNode != null;){
            currentNode = currentNode.left;
            height++;
        }
        return height;
    }
    int rightHeight(TreeNode root){
        TreeNode currentNode = root;
        int height;
        for (height = 0; currentNode != null;){
            currentNode = currentNode.right;
            height++;
        }
        return height;
    }
    int traverse(TreeNode root, int left, int right){
        if (root == null){
            return 0;
        }

        int leftHei;
        if (left != -1){
            leftHei = left;
        }else{
            leftHei = leftHeight(root);
        }
        int rightHei;
        if (right !=-1){
            rightHei = right;
        }else{
            rightHei = rightHeight(root);
        }

        if (leftHei == rightHei){
            root.val = (1 << leftHei) - 1;
        }else{
            root.val = traverse(root.left, leftHei-1, -1) + traverse(root.right, -1, rightHei-1) + 1;
        }
        return root.val;
    }
    public int countNodes(TreeNode root) {
        if (root != null) {
            traverse(root, -1, -1);
            return root.val;
        }else{
            return 0;
        }
    }
}
public class Count_Complete_Tree_Nodes {
    public static void main(String args[]){
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(1);
        TreeNode node3 = new TreeNode(1);
        node1.left = node2;
        node1.right= node3;
        Solution sol = new Solution();
        System.out.println(sol.countNodes(node1));
    }
}
