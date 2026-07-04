class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int prefix = nums[0];
        int res = INT_MIN;
        for (int i = 0; i < n; i++){
            prefix = min(nums[i], prefix);
            res = max(res, nums[i] - prefix);
        }
        if (res > 0) return res;
        return -1;
    }
};