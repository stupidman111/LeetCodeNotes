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
    vector<int> postOrderV;

    vector<int> postOrderTraversal(TreeNode* root) {
        if (root == nullptr) { return postOrderV; }
        traversal(root);
        return postOrderV;
    }

    void traversal(TreeNode* t) {
        stack<TreeNode*> s;
        s.push(t);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            //由于栈的先进先出特性：所以将后序(左右根)以根右左的顺序存入栈中，这样出栈时就能保证其左右根的顺序
            if (cur != nullptr) {
                s.pop();

                s.push(cur);
                s.push(nullptr);

                if (cur->right != nullptr) { s.push(cur->right); }
                if (cur->left != nullptr) { s.push(cur->left); }
            } else {
                s.pop();

                cur = s.top();
                s.pop();

                postOrderV.push_back(cur->val);
            }
        }
    }
};