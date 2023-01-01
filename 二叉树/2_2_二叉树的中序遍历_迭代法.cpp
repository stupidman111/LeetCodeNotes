//
// Created by 24563 on 2023/1/1.
//

#include <iostream>
#include <vector>
#include <stack>
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
        if (root == nullptr) { return inOrderV; }
        traversal(root);
        return inOrderV;
    }

    void traversal(TreeNode* t) {
        stack<TreeNode*> s;
        s.push(t);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            //由于栈的先进先出特性：所以将中序(左根右)以右根左的顺序存入栈中，这样出栈时就能保证其左根右的顺序
            if (cur != nullptr) {
                s.pop();

                if (cur->right != nullptr) { s.push(cur->right); }

                s.push(cur);
                s.push(nullptr);

                if (cur->left != nullptr) { s.push(cur->left); }
            } else {
                s.pop();

                cur = s.top();
                s.pop();

                inOrderV.push_back(cur->val);
            }
        }
    }
};