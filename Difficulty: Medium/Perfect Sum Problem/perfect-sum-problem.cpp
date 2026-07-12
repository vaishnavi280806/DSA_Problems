class Solution {
    int helper(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (target == 0 && idx < 0) return 1;
        if (idx < 0 || target < 0) return 0;
        if (dp[idx][target] != -1) return dp[idx][target];
        
        int pick = helper(idx-1, target - arr[idx], arr, dp);
        int notpick = helper(idx-1, target, arr, dp);
        
        return dp[idx][target] = pick + notpick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        return helper(arr.size() - 1, target, arr, dp);
    }
};