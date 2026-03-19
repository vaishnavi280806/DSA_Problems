class Solution {
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int up = 0, left = 0;
        if (i-1 >= 0 && grid[i-1][j] == 0) up = helper(i-1, j, grid, dp);
        if (j-1 >= 0 && grid[i][j-1] == 0) left = helper(i, j-1, grid, dp);

        return dp[i][j] = up + left;  

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return helper(m-1, n-1, grid, dp);
    }
};