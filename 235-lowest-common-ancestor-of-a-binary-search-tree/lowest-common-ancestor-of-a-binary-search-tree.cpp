/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        if (p->val > root->val && q->val > root->val){
            return helper(root->right, p, q);
        }
        else if (p->val < root->val && q->val < root->val){
            return helper(root->left, p, q);
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};