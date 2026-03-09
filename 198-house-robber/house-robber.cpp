class Solution {
    int helper(int idx, vector<int>& nums, vector<int>& dp){
        if (idx == 0) return nums[0];
        if (idx == 1) return max(nums[0], nums[1]);
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int maxi = INT_MIN;
        for (int i = idx - 2; i >= 0; i--){
            maxi = max(maxi, helper(i, nums, dp) + nums[idx]);
        }
        return dp[idx] = maxi;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        return max(helper(nums.size() - 1, nums, dp), helper(nums.size() - 2, nums, dp));
    }
};