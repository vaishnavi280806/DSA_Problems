/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    bool leaf(Node* node){
        return !node->left && !node->right;
    }
    void leftBoundary(Node* root, vector<int>& res){
        while(!leaf(root)){
            if (root->left){
                root = root->left;
            }
            else{
                root = root->right;
            }
            if (!leaf(root)) res.push_back(root->data);
        }
    }
    void leaves(Node* root, vector<int>& res){
        if (root == nullptr) return;
        if (leaf(root)) res.push_back(root->data);
        leaves(root->left, res);
        leaves(root->right, res);
    }
    void rightBoundary(Node* root, vector<int>& res){
        stack<int> stk;
        while(!leaf(root)){
            if (root->right){
                root = root->right;
            }
            else{
                root = root->left;
            }
            if (!leaf(root)) stk.push(root->data);
        }
        while(!stk.empty()){
            int num = stk.top();
            stk.pop();
            res.push_back(num);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        if (root == nullptr) return {};
        if (leaf(root)) return {root->data};
        vector<int> res;
        res.push_back(root->data);
        if (root->left) leftBoundary(root, res);
        leaves(root, res);
        if (root->right) rightBoundary(root, res);
        return res;
    }
};