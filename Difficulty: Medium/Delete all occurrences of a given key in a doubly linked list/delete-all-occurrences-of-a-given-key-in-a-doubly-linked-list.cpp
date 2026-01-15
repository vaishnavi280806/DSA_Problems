// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head, int x) {
        Node* cur = *head;
        while (cur != NULL){
            if (cur->data == x){
                if (cur == *head){
                    *head = (*head)->next;
                }
                Node* prevNode = cur->prev;
                Node* nextNode = cur->next;
                if (prevNode) cur->prev->next = nextNode;
                if (nextNode) cur->next->prev = prevNode;
                delete (cur);
                cur = nextNode;
            }
            else cur = cur->next;
        }
    }
};