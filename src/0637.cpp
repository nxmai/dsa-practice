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

vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> q;
    vector<double> res;
    double temp;
    int size, i;
    TreeNode* curr;
    
    q.push(root);
    
    while (!q.empty()) {
        temp = 0;
        size = q.size();
        
        for (i = 0; i < size; i++) {
            
            curr = q.front();
            q.pop();
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            
            temp += curr->val;
        }
        
        res.push_back((double)temp / size);
    }
    
    return res;
}