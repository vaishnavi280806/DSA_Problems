class Solution {
    int helper(int day, int task, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if (day == 0){
            int res = INT_MIN;
            for (int i = 0; i < 3; i++){
                if (i != task) res = max(res, mat[day][i]);
            }
            return res;
        }
        if (dp[day][task] != -1) return dp[day][task];
        
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++){
            if (i != task) maxi = max(maxi, mat[day][i] + helper(day-1, i, mat, dp));
        }
        return dp[day][task] = maxi;
    }
    
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        
        return helper(n-1, 3, mat, dp);
        
    }
};