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
class Node {
public:
    int maxi, mini, sum;
    Node(int sum, int maxi, int mini){
        this->sum = sum;
        this->maxi = maxi;
        this->mini = mini;
    }
};
class Solution {
    int ans = 0;
    Node helper(TreeNode* root){
        if (!root) return Node(0, INT_MIN, INT_MAX);
        Node left = helper(root->left);
        Node right = helper(root->right);
        if (root->val < right.mini && root->val > left.maxi){
            ans = max(root->val + left.sum + right.sum, ans);
            return Node(root->val + left.sum + right.sum, max(right.maxi, root->val), min(left.mini, root->val));
        }
        return Node(0, INT_MAX, INT_MIN);
    }
public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};