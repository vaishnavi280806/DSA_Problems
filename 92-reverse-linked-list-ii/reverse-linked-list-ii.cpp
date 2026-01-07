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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        for (int i = 0 ; i < left - 1; i++){
            prev = prev->next;
            cur = cur->next;
        }
        ListNode* prev2 = NULL;
        ListNode* temp = cur;
        ListNode* nextnode;
        for (int i = left; i <= right; i++){
            nextnode = cur->next;
            cur->next = prev2;
            prev2 = cur;
            cur = nextnode;
        }
        prev->next = prev2;
        temp->next = nextnode;

        return dummy->next;

    }
};