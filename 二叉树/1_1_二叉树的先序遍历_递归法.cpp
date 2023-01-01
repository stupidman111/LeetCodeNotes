//
// Created by 24563 on 2023/1/1.
//
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> preOrderV;

    vector<int> preOrderTraversal(TreeNode* root) {
        traversal(root);
        return preOrderV;
    }

    void traversal(TreeNode* t) {
        if (t == nullptr) { return; }

        preOrderV.push_back(t->val);//根
        traversal(t->left);//左
        traversal(t->right);//右
    }
};