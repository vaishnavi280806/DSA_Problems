/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> hash;
        Node* newHead = new Node(head->val);
        hash[head] = newHead;
        Node* newCur = newHead;
        Node* cur = head->next;
        while (cur != NULL){
            newCur->next = new Node(cur->val);
            newCur = newCur->next;
            hash[cur] = newCur;
            cur = cur->next;
        }
        cur = head;
        newCur = newHead;
        while (cur != NULL){
            if (cur->random){
                newCur->random = hash[cur->random];
            }
            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;



    }
};