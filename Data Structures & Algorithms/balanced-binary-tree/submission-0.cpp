/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left_h = dfs(root->left);
        int right_h = dfs(root->right);
        if(left_h == -1 || right_h == -1) return -1;
        if(abs(left_h - right_h) > 1) return -1;
        return 1 + max(left_h, right_h);
    }
    bool isBalanced(TreeNode* root) {
        if(dfs(root) == -1) return false;
        return true;
    }
};
