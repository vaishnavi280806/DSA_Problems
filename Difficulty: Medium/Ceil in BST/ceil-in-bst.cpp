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
  public:
    int findCeil(Node* root, int x) {
        int c = -1;
        while (root){
            if (root->data == x) return x;
            else if (root->data > x){
                c = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return c;
    }
};
