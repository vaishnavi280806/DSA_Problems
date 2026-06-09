/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if (node != nullptr){
                res += to_string(node->val) + ",";
            }
            else{
                res += "#,";
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#,") return {};
        string num = "";
        queue<TreeNode*> q;
        int idx = 0;
        while (data[idx] != ','){
            num += data[idx];
            idx++;
        }
        idx++;
        TreeNode* root = new TreeNode(stoi(num));
        num = "";
        q.push(root);
        TreeNode* cur = root;
        
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            while (data[idx] != ','){
                num += data[idx];
                idx++;
            }
            idx++;

            if (num != "#"){
                node->left = new TreeNode(stoi(num));
                q.push(node->left);
            }
            num = "";

            while (data[idx] != ','){
                num += data[idx];
                idx++;
            }
            idx++;
            if (num != "#"){
                node->right = new TreeNode(stoi(num));
                q.push(node->right);
            }
            num = "";
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));