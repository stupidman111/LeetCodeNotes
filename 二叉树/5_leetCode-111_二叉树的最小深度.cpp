//
// Created by 24563 on 2023/1/2.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }

    int getDepth(TreeNode* node) {
        if (node == nullptr) { return 0; }

        int left_depth = getDepth(node->left);
        int right_depth = getDepth(node->right);

        if (node->left != nullptr && node->right == nullptr) {
            return 1 + left_depth;
        }

        if (node->left == nullptr && node->right != nullptr) {
            return 1 + right_depth;
        }

        return 1 + min(left_depth, right_depth);
    }
};