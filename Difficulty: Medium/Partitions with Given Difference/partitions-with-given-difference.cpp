class Solution {
    int helper(int idx, vector<int>& arr, int sum, vector<vector<int>>& dp){
        if (idx == arr.size()){
            if (sum == 0) return 1;
            else return 0;
        }
        if (dp[idx][sum] != -1) return dp[idx][sum];
        int pick = 0;
        if (arr[idx] <= sum) pick = helper(idx + 1, arr, sum - arr[idx], dp);
        int notpick = helper(idx + 1, arr, sum, dp);
        return dp[idx][sum] = pick + notpick;
    }
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        int sum = (total + diff);
        if (sum%2  == 1) return 0;
        vector<vector<int>> dp(arr.size(), vector<int> (sum/2 + 1, -1));
        return helper(0, arr, sum/2, dp);
        
    }
};