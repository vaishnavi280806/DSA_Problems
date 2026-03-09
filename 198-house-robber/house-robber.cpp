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
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            int way1 = nums[i] + dp[i-2];
            int way2 = dp[i-1];
            dp[i] = max(way1, way2);
        }
        return dp[nums.size() - 1];
    }
};