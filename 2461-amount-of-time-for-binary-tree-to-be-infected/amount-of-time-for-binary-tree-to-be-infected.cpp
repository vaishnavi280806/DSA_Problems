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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map <TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* src;
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start) src = node;

            if (node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*, int> visited;
        q.push(src);
        visited[src] = 1;
        int res = -1;
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                visited[node] = 1;

                if (parent.count(node) && !visited[parent[node]]) q.push(parent[node]);
                if (node->left && !visited[node->left]) q.push(node->left);
                if (node->right && !visited[node->right]) q.push(node->right);
            }
            res++;
        }
        return res;
    }
};