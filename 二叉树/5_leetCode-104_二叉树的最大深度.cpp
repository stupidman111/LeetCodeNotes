//
// Created by 24563 on 2023/1/2.
//

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) { return 0; }
        return getDepth(root);
    }

    int getDepth(TreeNode* node) {
        if (node == nullptr) { return 0; }
        int left_depth = getDepth(node->left);
        int right_depth = getDepth(node->right);
        return 1 + max(left_depth, right_depth);
    }
};