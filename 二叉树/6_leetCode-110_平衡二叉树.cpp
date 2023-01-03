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
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }

    int getHeight(TreeNode* node) {//以当前节点node为根节点，判断该子树是否为平衡的，若为平衡则返回以node为根的子树的高度，否则返回-1
        if (node == nullptr) { return 0; }

        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) { return -1; }
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) { return -1; }

        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
};