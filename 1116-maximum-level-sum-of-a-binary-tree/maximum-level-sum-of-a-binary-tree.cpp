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
    int maxLevelSum(TreeNode* root) {
        int sum = INT_MIN, index = 0, level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int levelSum = 0; level++;
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;

                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            

            if (levelSum > sum){
                sum = levelSum;
                index = level;
            }
        }
        return index;
    }
};