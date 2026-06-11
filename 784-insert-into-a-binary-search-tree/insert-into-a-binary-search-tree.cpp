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
    /*TreeNode* helper(TreeNode* root, int val){
        if (!root) return new TreeNode(val);
        else if (root->val > val) root->left = helper(root->left, val);
        else root->right = helper(root->right, val);

        return root;
    }*/
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //return helper(root, val);

        if (!root) return new TreeNode(val);

        TreeNode* cur = root;
        while (true){
            if (cur->val > val){
                if (!cur->left){
                    cur->left = new TreeNode(val);
                    break;
                }
                else cur = cur->left;
            }
            else{
                if (!cur->right){
                    cur->right = new TreeNode(val);
                    break;
                }
                else cur = cur->right;
            }
        }
        return root;
    }
};