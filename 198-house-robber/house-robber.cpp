class Solution {
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