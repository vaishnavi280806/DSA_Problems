class Solution {
    int helper(int idx, vector<int>& arr, vector<vector<int>>& dp, int k){
        if (k == 0) return 1;
        if (k < 0 || idx < 0) return 0;
        
        if (dp[idx][k] != -1) return dp[idx][k];
        
        int pick = helper(idx -1, arr, dp, k - arr[idx]);
        int notpick = helper(idx - 1, arr, dp, k);
        
        return dp[idx][k] = pick | notpick;
    }
  public:
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        vector<vector<int>> dp(arr.size(), vector<int> (k+1, -1));
        
        return helper(arr.size() - 1, arr, dp, k);
    }
};