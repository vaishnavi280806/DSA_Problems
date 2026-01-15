/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node* cur = head->next;
        Node* temp;
        while (cur != NULL && cur->prev != NULL){
            if (cur->prev->data == cur->data){
                cur->prev->next = cur->next;
                temp = cur;
                if (cur->next) cur->next->prev = cur->prev;
                else cur->prev->next = NULL;
                cur = cur->next;
                delete temp;
            }
            else cur = cur->next;
        }
        return head;
    }
};