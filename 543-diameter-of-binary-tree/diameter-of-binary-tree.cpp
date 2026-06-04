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
    int maxi = INT_MIN;
    int helper(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int win = max(1 + left, 1 + right);
        maxi = max(maxi, 1 + left + right);
        return win;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxi - 1;
    }
};