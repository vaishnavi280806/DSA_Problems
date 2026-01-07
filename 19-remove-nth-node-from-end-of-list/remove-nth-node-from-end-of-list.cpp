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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* lead = dummy;
        while (n > 0){
            lead = lead->next;
            n--;
        }
        ListNode* lag = dummy;
        while (lead != NULL && lead->next != NULL){
            lag = lag->next;
            lead = lead->next;
        }

        if (lag->next != NULL) lag->next = lag->next->next;
        return dummy->next;
    }
};