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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& hash, int pStart, int pEnd, int iStart, int iEnd){
        if (iStart > iEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[pStart]);
        int idx = hash[preorder[pStart]];
        int left = idx - iStart;
        root->left = helper(preorder, inorder, hash, pStart + 1, pStart + left, iStart, idx - 1);
        root->right = helper(preorder, inorder, hash, pStart + left + 1, pEnd, idx + 1, iEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int, int> hash; //in inorder <val, idx>
        int n = inorder.size();
        for (int i = 0; i < n; i++){
            hash[inorder[i]] = i;
        }
        return helper(preorder, inorder, hash, 0, n-1, 0, n-1);

    }
};