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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n - 1;
        ListNode* cur = head;
        vector<vector<int>> res(m, vector<int>(n, -1));
        while (cur){
            for (int i = left; i <= right; i++){
                res[top][i] = cur->val;
                cur = cur->next;
                if (cur == NULL) break;
            }
            if (cur ==  NULL) break;
            top++;
            for (int i = top; i <= bottom; i++){
                res[i][right] = cur->val;
                cur = cur->next;
                if (cur ==  NULL) break;
            }
            if (cur ==  NULL) break;
            right--;
            for (int i = right; i >= left; i--){
                res[bottom][i] = cur->val;
                cur = cur->next;
                if (cur == NULL) break;
            }
            if (cur ==  NULL) break;
            bottom--;
            for (int i = bottom; i >= top; i--){
                res[i][left] = cur->val;
                cur = cur->next;
                if (cur == NULL) break;
            }
            if (cur ==  NULL) break;
            left++;
        }
        return res;
    }
};