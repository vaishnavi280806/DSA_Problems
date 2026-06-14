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
    unordered_set <int> hash;
    bool helper(TreeNode* root, int k){
        if (!root) return false;
        if (hash.count(k - root->val)) return true;
        hash.insert(root->val);
        return helper(root->right, k) || helper(root->left, k); 
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return helper(root, k);
    }
};