class Solution {
    int helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if (idx == nums.size()){
            if (target == 0) return 1;
            return 0;
        }
        if (dp[idx][target] != -1) return dp[idx][target];
        int pick = 0;
        if (nums[idx] <= target) pick = helper(idx + 1, target - nums[idx], nums, dp);
        int notpick = helper(idx + 1, target, nums, dp);

        return dp[idx][target] = pick + notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0) + abs(target);
        if (total % 2) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (total/2 + 1, -1));
        return helper(0, total/2, nums, dp);
    }
};