class Solution {
    int helper(int idx, int cap, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if (idx == 0){
            return cap/wt[0] * val[0];
        }
        if (dp[idx][cap] != -1) return dp[idx][cap];
        
        int pick = 0;
        if (cap >= wt[idx]) pick = val[idx] + helper(idx, cap - wt[idx], val, wt, dp);
        int notpick = helper(idx-1, cap, val, wt, dp);
        
        return dp[idx][cap] = max(pick, notpick);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
        return helper(n-1, capacity, val, wt, dp);
    }
};