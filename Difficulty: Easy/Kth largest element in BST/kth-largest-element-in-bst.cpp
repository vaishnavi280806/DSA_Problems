/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
    void len(Node* root, int& cnt){
        if (!root) return;
        cnt++;
        len(root->left, cnt);
        len(root->right, cnt);
    }
    int c = 0;
    int helper(Node* root, int k){
        if (!root) return -1;
        int left = helper(root->left, k);
        if (left != -1) return left;
        c++;
        if (c == k) return root->data;
        int right = helper(root->right, k);
        if (right != -1) return right;
    }
  public:
    int kthLargest(Node *root, int k) {
        int cnt = 0;
        len(root, cnt);
        return helper(root, cnt - k + 1);
    }
};