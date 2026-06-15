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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    void helper(TreeNode* root){
        if (!root) return;
        helper(root->left);
        if (prev && prev->val > root->val){
            if (!first){
                first = prev;
                mid = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        helper(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = mid = last = prev = nullptr;
        helper(root);
        if (first && last) swap(first->val, last->val);
        else swap(first->val, mid->val);
    }
};