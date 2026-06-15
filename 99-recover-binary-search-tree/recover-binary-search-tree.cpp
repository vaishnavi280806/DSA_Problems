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
    TreeNode* next(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right){
            TreeNode* cur = node->right;
            while (cur){
                stk.push(cur);
                cur = cur->left;
            }
        }
        return node;
    }
    TreeNode* before(stack<TreeNode*>& stk){
        TreeNode* node = stk.top();
        stk.pop();
        if (node->left){
            TreeNode* cur = node->left;
            while (cur){
                stk.push(cur);
                cur = cur->right;
            }
        }
        return node;
    }
public:
    void recoverTree(TreeNode* root) {
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
        TreeNode* prev = next(nexts);
        TreeNode* tar1;
        TreeNode* tar2;
        while(true){
            cur = next(nexts);
            if (prev->val > cur->val){
                tar1 = prev;
                break;
            }
            prev = cur;
        }

        prev = before(befores);
        while(true){
            cur = before(befores);
            if (prev->val < cur->val){
                tar2 = prev;
                break;
            }
            prev = cur;
        }
        int x = tar1->val;
        tar1->val = tar2->val;
        tar2->val = x;
    }
};