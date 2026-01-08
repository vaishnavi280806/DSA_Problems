/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA != NULL || curB != NULL){
            if (curA == NULL) curA = headB;
            else curA = curA->next;
            if (curB == NULL) curB = headA;
            else curB = curB->next;
            if (curA == curB) return curA;
        }
        return NULL;
    }
};