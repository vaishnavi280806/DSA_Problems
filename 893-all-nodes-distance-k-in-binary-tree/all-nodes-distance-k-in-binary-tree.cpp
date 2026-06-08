/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map <TreeNode*, int> visited;
        q.push(target);
        visited[target] = 1;
        for (int i = 0; i < k; i++){
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode* node = q.front();
                visited[node] = 1;
                q.pop();

                if (parent.count(node) && !visited[parent[node]]) q.push(parent[node]);
                if (node->left && !visited[node->left]) q.push(node->left);
                if (node->right && !visited[node->right]) q.push(node->right);
            }
        }
        vector<int> res;
        while (!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};