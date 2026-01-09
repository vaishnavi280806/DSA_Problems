/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        Node* zeroH = new Node(-1); 
        Node* zero = zeroH;
        Node* oneH = new Node(-1); 
        Node* one = oneH;
        Node* twoH = new Node(-1);
        Node* two = twoH;
        
        Node* cur = head;
        while (cur != NULL){
            if (cur->data == 0){
                zero->next = cur;
                zero = cur;
            }
            else if (cur->data == 1){
                one->next = cur;
                one = cur;
            }
            else{
                two->next = cur;
                two = cur;
            }
            cur = cur->next;
        }
        two->next = NULL;
        zero->next = (oneH->next != NULL) ? oneH->next : twoH->next;
        one->next = twoH->next;
        return zeroH->next;
    }
};