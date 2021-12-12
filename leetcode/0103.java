import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        
        if(root == null) 
            return new ArrayList<>();
        
        boolean leftToRight = true;
        q.add(root);
        
        while(!q.isEmpty()){
            List<Integer> tmp = new LinkedList<>();
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode top = q.peek();
                q.remove();
                if(leftToRight)
                    tmp.add(top.val);
                else 
                    tmp.add(0, top.val);
                
                if(top.left != null) q.add(top.left);
                if(top.right != null) q.add(top.right);
            }
            res.add(tmp);
            leftToRight = !leftToRight;
        }
        return res;
    }
}