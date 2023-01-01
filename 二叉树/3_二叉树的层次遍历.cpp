//
// Created by 24563 on 2023/1/1.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    vector<vector<int>> levelOrderV;

    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        if (root == nullptr) { return levelOrderV; }
        traversal(root);
        return levelOrderV;
    }

    void traversal(TreeNode* t) {
        queue<TreeNode*> q;
        q.push(t);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();

                temp.push_back(cur->val);

                if (cur->left != nullptr) { q.push(cur->left); }
                if (cur->right != nullptr) { q.push(cur->right); }
            }

            levelOrderV.push_back(temp);
        }
    }
};