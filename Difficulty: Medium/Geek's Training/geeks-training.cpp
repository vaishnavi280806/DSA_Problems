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
        vector<vector<int>> dp(mat.size() + 1, vector<int> (4, -1));
        return helper(mat.size() - 1, 3, mat, dp);
    }
};