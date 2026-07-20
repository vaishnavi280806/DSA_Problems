class Solution {
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if (j < i) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for (int k = i; k <= j; k++){
            int cost = (nums[i-1] * nums[k] * nums[j+1]) + helper(i, k-1, nums, dp) + helper(k+1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int prev = 1;

        for (int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            nums[i] = prev;
            prev = temp;
        }
        nums.push_back(prev);
        nums.push_back(1);

        vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() +1, -1));
        return helper(1, nums.size() - 2, nums, dp);
    }
};