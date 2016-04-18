package com.helloqiji;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by qiji on 4/18/16.
 */
class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
     }
public class Binary_Tree_Right_Side_View {
    public static void main(String args[]){
        TreeNode node1 = new TreeNode(1);
        TreeNode node2 = new TreeNode(2);
        TreeNode node3 = new TreeNode(3);
        node2.left = node2;
        node1.right= node3;
        Solution sol = new Solution();
        System.out.println(sol.rightSideView(node1));
    }

}
class Solution {
    int currentHeight, maxHeight;
    List<Integer> ans;
    Solution(){
        currentHeight = 1;
        maxHeight = 0;
        ans = new ArrayList<Integer>();
    }

    public List<Integer> rightSideView(TreeNode root) {
        if (root == null){
            return ans;
        }
        if (currentHeight > maxHeight) {
            this.ans.add(root.val);
            maxHeight = currentHeight;
        }
        currentHeight++;
        rightSideView(root.right);
        rightSideView(root.left);
        currentHeight--;
        return ans;
    }
}
