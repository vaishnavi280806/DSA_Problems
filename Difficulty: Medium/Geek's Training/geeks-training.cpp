class Solution {
    int helper(int idx, int last, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if (idx == 0){
            int maxi = INT_MIN;
            for (int i = 0; i < 3; i++){
                if (i != last) maxi = max(maxi, mat[0][i]);
            }
            return maxi;
        }
        if (dp[idx][last] != -1) return dp[idx][last];
        int maxi = INT_MIN;
        for(int i = 0; i < 3; i++){
            if (i != last){
                maxi = max(maxi, mat[idx][i] + helper(idx - 1, i, mat, dp));
            }
        }
        return dp[idx][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        
        for (int i = 1; i < n; i++){
            for (int last = 0; last < 4; last++){
                for (int j = 0; j <  3; j++){
                    if (j != last){
                        dp[i][last] = max(dp[i][last], mat[i][j] + dp[i-1][j]);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};