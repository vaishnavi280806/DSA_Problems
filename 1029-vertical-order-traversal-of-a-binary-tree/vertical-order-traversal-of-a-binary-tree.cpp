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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans[node.second.first][node.second.second].insert(node.first->val);
            if (node.first->left){
                q.push({node.first->left, {node.second.first - 1, node.second.second + 1}});
            }
            if (node.first->right){
                q.push({node.first->right, {node.second.first + 1, node.second.second + 1}});
            }
        }
        vector<vector<int>> res;
        for (auto x : ans){
            vector<int> temp;
            for (auto y : x.second){
                temp.insert(temp.end(), y.second.begin(), y.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};