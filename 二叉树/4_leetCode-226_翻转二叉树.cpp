//
// Created by 24563 on 2023/1/1.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) { return nullptr; }

        swap(root->left, root->right);//根
        invertTree(root->left);//左
        invertTree(root->right);//右

        return root;
    }
};