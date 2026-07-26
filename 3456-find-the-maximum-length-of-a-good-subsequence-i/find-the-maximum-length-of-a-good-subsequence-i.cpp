class Solution {
    int helper(int idx, int k, int prev, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if (idx >= nums.size()) return 0;
        if (dp[idx][k][prev+1] != -1) return dp[idx][k][prev+1];

        int nottake = helper(idx+1, k, prev, nums, dp);
        int take = 0;
        if (prev == -1) take = 1 + helper(idx+1, k, idx, nums, dp);
        else if (nums[idx] == nums[prev]) take = 1 + helper(idx+1, k, idx, nums, dp);
        else if (k > 0) take = 1 + helper(idx+1, k-1, idx, nums, dp);


        return dp[idx][k][prev+1] = max(take, nottake);


    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k+1, vector<int> (n+1, -1)));
        return helper(0, k, -1, nums, dp);
    }
};