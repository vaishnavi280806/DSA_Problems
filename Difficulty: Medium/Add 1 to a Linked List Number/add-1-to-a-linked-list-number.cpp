/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    int helper(Node* head, int carry){
        if (head->next == NULL){
            int sum = head->data + 1;
            head->data = sum % 10;
            return sum/10;
        }
        carry = helper(head->next, carry);
        int sum = head->data + carry;
        head->data = sum % 10;
        return sum/10;
    }
  public:
    Node* addOne(Node* head) {
        int carry = helper(head, 1);
        if (carry == 1){
            Node* newnode = new Node(1);
            newnode->next = head;
            head = newnode;
        }
        return head;
    }
};