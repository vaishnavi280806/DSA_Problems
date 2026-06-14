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
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack <TreeNode*> stk;
        TreeNode* root = new TreeNode(preorder[0]);
        stk.push(root);
        TreeNode* cur = root;
        TreeNode* node;
        int i = 1;
        while(i < preorder.size()){
            if (preorder[i] < stk.top()->val){
                node = new TreeNode(preorder[i]);
                cur->left = node;
            }
            else{
                while(!stk.empty() && stk.top()->val < preorder[i]){
                    cur = stk.top();
                    stk.pop();
                }
                node = new TreeNode(preorder[i]);
                cur->right = node;
            }
            cur = node;
            stk.push(cur);
            i++;
        }
        return root;
    }
};