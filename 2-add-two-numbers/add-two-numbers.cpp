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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1->next;
        ListNode* cur2 = l2->next;
        int sum = l1->val + l2->val;
        ListNode* head = new ListNode(sum%10);
        ListNode* cur = head;
        int carry = sum/10;
        while (cur1 != NULL || cur2 != NULL){
            sum = carry;
            if (cur1 != NULL){
                sum += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != NULL){
                sum += cur2->val;
                cur2 = cur2->next;
            }
            ListNode* newnode = new ListNode(sum%10);
            carry = sum/10;
            cur->next = newnode;
            cur = newnode;

        }
        while (carry != 0){
            ListNode* newnode = new ListNode(carry%10);
            cur->next = newnode;
            carry = carry/10;
            cur = newnode;
        }
        return head;
    }
};