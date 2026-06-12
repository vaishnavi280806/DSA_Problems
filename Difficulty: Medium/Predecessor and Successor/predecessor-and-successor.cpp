/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> res(2);
        Node* temp = root;
        while (root){
            if (root->data >= key) root = root->left;
            else{
                res[0] = root;
                root = root->right;
            }
        }
        root = temp;
        while (root){
            if (root->data <= key) root = root->right;
            else{
                res[1] = root;
                root = root->left;
            }
        }
        return res;
    }
};