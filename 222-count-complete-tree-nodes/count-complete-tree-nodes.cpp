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
    int helper(TreeNode* root){
        if (!root) return 0;
        int l = 1, r = 1;
        TreeNode* temp = root;
        while(temp->left){
            l++;
            temp = temp->left;
        }
        temp = root;
        while(temp->right){
            r++;
            temp = temp->right;
        }
        if (l == r)return pow(2, l) - 1;
        else return 1 + helper(root->left) + helper(root->right);
    }
public:
    int countNodes(TreeNode* root) {
        //if (!root) return 0;
        return helper(root);
    }
};