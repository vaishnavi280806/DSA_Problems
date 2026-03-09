class Solution {
    int helper(int idx, vector<int>& nums, vector<int>& dp){
        if (idx == 0) return nums[0];
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int way1 = nums[idx] + helper(idx - 2, nums, dp);
        int way2 = helper(idx - 1, nums, dp);
        return dp[idx] = max(way1, way2);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums.size() - 1, nums, dp);
    }
};