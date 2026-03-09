class Solution {
    int helper(int idx, vector<int>& height, vector<int>& dp){
        if (idx == 0) return 0; 
        if (dp[idx] != -1) return dp[idx];
        int way2 = INT_MAX;
        int way1 = helper(idx - 1, height, dp) + abs(height[idx] - height[idx - 1]);
        if (idx > 1) way2 = helper(idx - 2, height, dp) + abs(height[idx] - height[idx - 2]);
        return dp[idx] = min(way1, way2);
    }
  public:
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1);
        return helper(height.size() - 1, height, dp);
    }
};