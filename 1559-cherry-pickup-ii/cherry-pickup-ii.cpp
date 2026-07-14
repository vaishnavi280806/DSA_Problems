class Solution {
    int helper(int i, int j, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if (i >= grid.size() || j < 0 || j >= grid[0].size() || k < 0 || k >= grid[0].size()) return -1e5;
        if (i == grid.size() -1){
            if (j != k) return grid[i][j] + grid[i][k];
            return grid[i][j];
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int maxi  = INT_MIN;
        for (int r1 = -1; r1 <= 1; r1++){
            for (int r2 = -1; r2 <= 1; r2++){
                if (j != k) maxi = max(maxi, grid[i][j] + grid[i][k] + helper(i+1, j + r1, k+r2, grid, dp));
                else maxi = max(maxi, grid[i][j] + helper(i+1, j + r1, k+r2, grid, dp));
            }
        }
        return dp[i][j][k] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, -1)));
        return helper(0, 0, n-1, grid, dp);
    }
};