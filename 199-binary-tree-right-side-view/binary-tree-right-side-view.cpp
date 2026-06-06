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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        map<int, int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto temp = q.front();
            TreeNode* node = temp.first;
            q.pop();
            int y = temp.second;
            ans[y] = node->val;

            if (node->left) q.push({node->left, y + 1});
            if (node->right) q.push({node->right, y + 1});
        }
        vector<int> res;
        for (auto x : ans){
            res.push_back(x.second);
        }
        return res;
    }
};