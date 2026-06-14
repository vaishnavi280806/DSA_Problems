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
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        while (root){
            stk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right){
            TreeNode* cur = node->right;
            while (cur){
                stk.push(cur);
                cur = cur->left;
            }
        }
        return node->val;
    }
    
    bool hasNext() {
        if (stk.empty()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */