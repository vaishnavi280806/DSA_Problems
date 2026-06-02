/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        Node* node = root;
        vector<int> res;
        stack<Node*> stk;
        
        while(true){
            if (node){
                stk.push(node);
                node = node->left;
            }
            else{
                if (stk.empty()) break;
                Node* temp = stk.top();
                stk.pop();
                res.push_back(temp->data);
                node = temp->right;
            }
        }
        return res;
    }
};