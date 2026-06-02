/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) {
        stack<Node*> stk;
        stk.push(root);
        vector<int> res;
        while (!stk.empty()){
            Node* node = stk.top();
            stk.pop();
            res.push_back(node->data);
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        return res;
    }
};