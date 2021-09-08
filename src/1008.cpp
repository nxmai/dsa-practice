#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* build(vector<int>pre, int l, int r)
{
    if (l > r)
        return nullptr;
    TreeNode* root = new TreeNode(pre[l]);
    if (l == r)
        return root;

    int ind = l + 1;
    while (ind <= r && pre[ind] < pre[l]) {
        ind++;
    }
    
    root->left = build(pre, l + 1, ind - 1);
    root->right = build(pre, ind, r);

    return root;

}