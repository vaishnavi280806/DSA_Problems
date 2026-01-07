/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nextnode = head;
        while (nextnode != NULL){
            nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode; 
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2->next != NULL && p2->next->next != NULL){
            p2 = p2->next->next;
            p1 = p1->next;
        }
        p2 = reverse(p1->next);
        p1 = head;
        while (p1 != NULL && p2 != NULL){
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;

    }
};