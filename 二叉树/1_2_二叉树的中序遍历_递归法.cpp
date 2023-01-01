//
// Created by 24563 on 2023/1/1.
//
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    vector<int> inOrderV;

    vector<int> inOrderTraversal(TreeNode* root) {
        traversal(root);
        return inOrderV;
    }

    void traversal(TreeNode* t) {
        if (t == nullptr) { return; }

        traversal(t->left);//左
        inOrderV.push_back(t->val);//中
        traversal(t->right);//右
    }
};