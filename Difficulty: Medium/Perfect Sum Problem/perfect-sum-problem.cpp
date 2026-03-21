class Solution {
    int helper(int idx, vector<int>& arr, int target, vector<vector<int>>& dp){
        if (idx == arr.size()){
            if (target == 0) return 1;
            else return 0;
        }
        if (dp[idx][target] != -1) return dp[idx][target];
        
        int pick = 0;
        if (arr[idx] <= target) pick = helper(idx + 1, arr, target - arr[idx], dp);
        int notpick = helper(idx + 1, arr, target, dp);
        
        return dp[idx][target] = pick + notpick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int> (target+1, -1));
        return helper(0, arr, target, dp);
    }
};