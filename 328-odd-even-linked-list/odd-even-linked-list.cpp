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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* head2 = head->next;
        ListNode* cur1 = head;
        ListNode* cur2 = head2;

        while (cur2 != NULL && cur2->next !=NULL){
            cur1->next = cur1->next->next;
            cur2->next = cur2->next->next;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        cur1->next = head2;
        return head;

    }
};