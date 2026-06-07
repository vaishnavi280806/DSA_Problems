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
    void helper(TreeNode* root, string ds, vector<string>& res){
        if (!root) return;
        if (root->left || root->right) ds += to_string(root->val) + "->";
        else{
            ds += to_string(root->val);
            res.push_back(ds);
        }
        helper(root->left, ds, res);
        helper(root->right, ds, res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds = "";
        vector<string> res;
        helper(root, ds, res);
        return res;
    }
};