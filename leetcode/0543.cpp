#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
int ans;
int diameterOfBinaryTree(TreeNode* root) {
    ans=1;
    depth(root);
    return ans-1;
}

int depth(TreeNode* root){
    if(root==NULL)
        return 0;
    
    int l = depth(root->left);
    int r = depth(root->right);
        
    ans = max(ans, l + r +1);
    return max(l,r) +1;
    
}