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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        int res = 0;
        q.push({root, 0});

        while(!q.empty()){
            int n = q.size();
            long long first = 0, last = 0;
            for (int i = 0; i < n; i++){
                auto temp = q.front();
                TreeNode* node = temp.first;
                long long idx = temp.second;
                q.pop();

                if (i == 0) first = idx;
                else if (i == n-1) last = idx;

                if (node->left) q.push({node->left, 2*idx + 1 - first});
                if (node->right) q.push({node->right, 2*idx + 2 - first});
            }
            //cout << first << " " << last << endl;
            res = max(res,(int)(last - first + 1));

        }
        return res;
    }
};