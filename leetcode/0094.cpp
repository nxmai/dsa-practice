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

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *current = root;

    while (st.empty() == false || current != NULL)
    {
        while (current != NULL)
        {
            st.push(current);
            current = current->left;
        }

        TreeNode *node = st.top();
        res.push_back(node->val);
        st.pop();
        current = node->right;
    }
    return res;
}