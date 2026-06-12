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
    bool helper(TreeNode* root, long long maxi, long long mini){
        if (!root) return true;
        if (root->val <= maxi && root->val >= mini){
            if (helper(root->left, (long long)root->val - 1, mini) && helper(root->right, maxi, (long long)root->val + 1)) return true;
            else return false;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MAX, INT_MIN);
    }
};