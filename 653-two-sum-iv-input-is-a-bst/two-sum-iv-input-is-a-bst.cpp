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
    void next(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right){
            TreeNode* cur = node->right;
            while (cur){
                stk.push(cur);
                cur = cur->left;
            }
        }
    }
    void before(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();
        stk.pop();
        if (node->left){
            TreeNode* cur = node->left;
            while (cur){
                stk.push(cur);
                cur = cur->right;
            }
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root->left && !root->right) return false;
        stack<TreeNode*> nexts;
        stack<TreeNode*> befores;
        TreeNode* cur = root;
        while (cur){
            nexts.push(cur);
            cur = cur->left;
        }
        cur = root;
        while (cur){
            befores.push(cur);
            cur = cur->right;
        }
        while (!nexts.empty() && !befores.empty() && nexts.top()->val < befores.top()->val){
            if (nexts.top()->val + befores.top()->val == k) return true;
            else if (nexts.top()->val + befores.top()->val > k) before(befores);
            else next(nexts);
        }
        return false;
    }
};