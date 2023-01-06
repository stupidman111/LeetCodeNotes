//
// Created by 24563 on 2023/1/6.
//
#include <iostream>
#include <vector>
#include <string>
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
    vector<int> path;
    vector<string> str_path;

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) { return {}; }
        traversal(root);
        return str_path;
    }

    void traversal(TreeNode* node) {
        path.push_back(node->val);

        /**
         * 当且仅当当前节点的左、右孩子都为nullptr时，才将path转换为string形式保存到str_path中
         */
        if (node->left == nullptr && node->right == nullptr) {
            string str;
            for (const int& val : path) {
                str += to_string(val);
                str += "->";
            }
            str.pop_back();
            str.pop_back();
            str_path.push_back(str);
        }
        

        if (node->left) {
            traversal(node->left);
            path.pop_back();//回溯
        }

        if (node->right) {
            traversal(node->right);
            path.pop_back();//回溯
        }
    }
};