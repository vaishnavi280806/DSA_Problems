// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> v;
        Node* left = head;
        Node* right = head;
        while (right->next) right = right->next;
        while (left != right && right->next != left){
            if (left->data + right->data == target){
                v.push_back({left->data, right->data});
                right = right->prev;
                left = left->next;
            }
            else if (left->data + right->data > target){
                right = right->prev;
            }
            else left = left->next;
        }
        return v;
    }
};