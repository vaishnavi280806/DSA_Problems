class Solution {
    int helper(int i, int j, int k, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
        if (i < 0 || i >= m || j < 0 || j >= n || k < 0 || k >= n) return -1e5;
        if (i == m-1){
            if (j != k) return grid[m-1][j] + grid[m-1][k];
            else return grid[m-1][j];
        }
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int maxi = -1e5;
        int ans;
        for (int r1 = -1; r1 <= 1; r1++){
            for (int r2 = -1; r2 <= 1; r2++){
                if (j != k) ans = grid[i][j] + grid[i][k] + helper(i+1, j + r1, k + r2, grid, m, n, dp);
                else ans = grid[i][j] + helper(i+1, j + r1, k + r2, grid, m, n, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j][k] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp (m, vector<vector<int>> (n, vector<int> (n, -1)));
        return helper(0, 0, n-1, grid, m, n, dp);
    }
};