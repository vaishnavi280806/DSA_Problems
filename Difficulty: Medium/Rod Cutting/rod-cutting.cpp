// User function Template for C++

int helper(int idx, int n, vector<int>& price, vector<vector<int>>& dp){
    if (idx == 0){
        return n * price[0];
    }
    if (dp[idx][n] != -1) return dp[idx][n];
    int pick = 0;
    if (idx + 1 <= n) pick = price[idx] + helper(idx, n - idx - 1, price, dp);
    int notpick = helper(idx - 1, n, price, dp);
    
    return dp[idx][n] = max(pick, notpick);
}

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp (n, vector<int> (n+1, -1));
        return helper(n-1, n, price, dp);
        
    }
};