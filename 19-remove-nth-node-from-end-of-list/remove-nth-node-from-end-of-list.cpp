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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* lead = dummy;

        while (n--){
            lead = lead->next;
        }
        ListNode* lag = dummy;
        while (lead && lead->next){
            lead = lead->next;
            lag = lag->next;
        }
        if (lag && lag->next){
            lag->next = lag->next->next;
        }
        return dummy->next;

    }
};