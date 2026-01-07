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
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* prev;
        while (cur->next != NULL){
            cur->val = cur->next->val;
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
    }
};