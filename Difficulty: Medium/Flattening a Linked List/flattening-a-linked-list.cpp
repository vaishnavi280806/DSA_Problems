/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
    Node* merge(Node* cur1, Node* cur2){
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        while (cur1 != NULL && cur2 != NULL){
            if (cur1->data < cur2->data){
                cur->bottom = cur1;
                cur = cur1;
                cur1 = cur1->bottom;
            }
            else{
                cur->bottom = cur2;
                cur = cur2;
                cur2 = cur2->bottom;
            }
        }
        if (cur1 == NULL) cur->bottom = cur2;
        else cur->bottom = cur1;
        return dummy->bottom;
    }
  public:
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) return root;
        Node* merged = flatten(root->next);
        return merge(root, merged);
        
        
    }
};