#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return {};
    vector<int> res;
    stack<TreeNode* > st;
    
    st.push(root);
    
    while(st.empty() == false){
        TreeNode *node = st.top();
        res.push_back(node->val);
        st.pop();
        if(node->right)
            st.push(node->right);
        if(node->left)
            st.push(node->left);
    }
    
    return res;
}