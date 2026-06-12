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
    int c = 0;
    int helper(TreeNode* root, int k){
        if (!root) return -1;
        int left = helper(root->left, k);
        if (left != -1) return left;
        c++;
        if (c == k) return root->val;
        int right = helper(root->right, k);
        if (right != -1) return right;

        return -1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return helper(root, k);
    }
};