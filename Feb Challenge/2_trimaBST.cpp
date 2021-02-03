#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

void InorderBST(TreeNode* root) {
    if (!root)
        return;
    InorderBST(root->left);
    cout << root->val;
    InorderBST(root->right);
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }

    return root;
}

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root)
        return NULL;

    if (root->val > high)
        return trimBST(root->left, low, high);
    if (root->val < low)
        return trimBST(root->right, low, high);

    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 3);
    root = insert(root, 0);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);

    trimBST(root, 1, 3);
    InorderBST(root);

    return 0;
}