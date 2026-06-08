/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
    bool helper(Node* root){
        if (!root->left && !root->right){
            return true;
        }
        else if (!root->left) return helper(root->right) && root->data == root->right->data;
        else if (!root->right) return helper(root->left) && root->data == root->left->data;
        
        if (root->left->data + root->right->data == root->data){
            if (helper(root->left) && helper(root->right)) return true;
            else return false;
        }
        else return false;
    }
  public:
    bool isSumProperty(Node *root) {
        return helper(root);
    }
};