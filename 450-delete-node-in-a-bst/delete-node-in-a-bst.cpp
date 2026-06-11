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
    TreeNode* suc(TreeNode* root){
        root = root->right;
        while (root->left) root = root->left;
        return root;
    }
    TreeNode* helper(TreeNode* root, int key){
        if (!root) return nullptr;
        if (root->val < key) root->right = helper(root->right, key);
        else if (root->val > key) root->left = helper(root->left, key);
        else{
            if (!root->left){
                TreeNode* temp = root->right;
                delete(root);
                return temp;
            }
            else if (!root->right){
                TreeNode* temp = root->left;
                delete(root);
                return temp;
            }
            else{
                TreeNode* temp = suc(root);
                root->val = temp->val;
                root->right = helper(root->right, temp->val);
            }
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return helper(root, key);
    }
};