class Solution {
    bool helper(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if (target == 0) return true;
        if (idx == 0){
            if (target == arr[0]) return true;
            return false;
        }
        if (dp[idx][target] != -1) return dp[idx][target];
        bool nottake = helper(idx - 1, target, arr, dp);
        bool take = false;
        if (arr[idx] <= target) take = helper(idx - 1, target - arr[idx], arr, dp);
        return dp[idx][target] = nottake || take;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp (arr.size(), vector<int> (sum + 1, -1));
        return helper(arr.size() - 1, sum, arr, dp);
    }
};