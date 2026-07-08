class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int l = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++){
            if (nums[r] == 0){
                l = r + 1;
            }
            else res = max(res, r - l + 1);
        }
        return res;
    }
};