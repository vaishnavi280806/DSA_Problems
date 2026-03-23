class Solution {
    int helper(int idx, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if (idx == 0){
            if (wt[0] <= W) return val[0];
            else return 0;
        }
        if (dp[idx][W] != -1) return dp[idx][W];
        int pick = 0;
        if (W - wt[idx] >= 0) pick = val[idx] + helper(idx - 1, W - wt[idx], val, wt, dp);
        int notpick = helper(idx - 1, W, val, wt, dp);
        
        return dp[idx][W] = max(pick, notpick);
        
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp (n, vector<int> (W+1, -1));
        return helper(n-1, W, val, wt, dp);
    }
};