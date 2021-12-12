
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> res = new ArrayList<>();
        if(root == null){
            return new ArrayList<>();
        }
        q.add(root);
        
        while(!q.isEmpty()){
            List<Integer> temp = new ArrayList<>();
            int len = q.size();
            for(int i = 0; i < len; i++){
                TreeNode top = q.peek();
                q.remove();
                temp.add(top.val);
                
                if(top.left != null){
                    q.add(top.left);
                }
                if(top.right != null){
                    q.add(top.right);
                }
            }
            res.add(temp);
        }
        
        return res;
    }
}
