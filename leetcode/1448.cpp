#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

void good(TreeNode* root, int max, int &count){
    if(root == nullptr)
        return;
    
    if(root->val >= max)
        count++;
    
    int max_local = root->val >= max ? root->val : max;
    good(root->left, max_local, count);
    good(root->right, max_local, count);
    return ;
}

int goodNodes(TreeNode* root) {
    int count = 0;
    good(root, root->val, count);
    return count;
}