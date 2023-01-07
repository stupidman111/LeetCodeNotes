//
// Created by 24563 on 2023/1/7.
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) { return 0; }

        int left_val = sumOfLeftLeaves(root->left);

        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) {
            left_val = root->left->val;
        }

        int right_val = sumOfLeftLeaves(root->right);

        return left_val + right_val;
    }
};