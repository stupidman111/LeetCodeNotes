//
// Created by 24563 on 2023/1/3.
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
    int countNodes(TreeNode* root) {
        return getNode_Nodes(root);
    }

    int getNode_Nodes(TreeNode* node) {
        if (node == nullptr) { return 0; }

        int left_Depth = 0, right_Depth = 0;

        TreeNode* left_node = node->left;
        TreeNode* right_node = node->right;

        while (left_node) {
            left_node = left_node->left;
            left_Depth++;
        }

        while (right_node) {
            right_node = right_node->right;
            right_Depth++;
        }

        if (left_Depth == right_Depth) {
            return (2 << left_Depth) - 1;
        }

        return 1 + getNode_Nodes(node->left) + getNode_Nodes(node->right);
    }
};