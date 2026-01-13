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
    ListNode* findkthNode(ListNode* head, int k){
        int count = 1;
        while (count < k && head != NULL){
            head = head->next;
            count++;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* nextnode = cur;
        while (nextnode != NULL){
            nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* nextnode;
        ListNode* temp;
        bool flag = false;
        while (cur != NULL){
            ListNode* kthNode = findkthNode(cur, k);
            if (kthNode == NULL && prev){
                prev->next = cur;
                break;
            }
            nextnode = kthNode->next;
            kthNode->next = NULL;
            temp = reverse(cur);
            if (flag == false){
                head = temp;
                flag = true;
            }
            else{

                prev->next = kthNode;
            }
            prev = cur;
            cur = nextnode;

        }
        return head;

    }
};