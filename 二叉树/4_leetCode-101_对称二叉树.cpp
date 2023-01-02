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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) { return true; }
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode* left_node,TreeNode* right_node) {
        /*
         * 左为空、右也为空-->true
         * 左不为空、右为空-->false
         * 左为空、右不为空-->false
         * 左值 != 右值-->false
         *
         * 计算外、内
         */
        if (left_node == nullptr && right_node == nullptr) { return true; }
        else if (left_node != nullptr && right_node == nullptr) { return false; }
        else if (left_node == nullptr && right_node != nullptr) { return false; }
        else if (left_node->val != right_node->val) { return false; }

        bool outFlag = isSame(left_node->left, right_node->right);
        bool inFlag = isSame(left_node->right, right_node->left);
        bool Flag = outFlag && inFlag;
        return Flag;
    }
};