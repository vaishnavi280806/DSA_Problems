class Solution {
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if (i == 0 && j == 0) return triangle[0][0];
        if (j < 0 || j > i) return 1e5;
        if (dp[i][j] != -1) return dp[i][j];
        int way1 = triangle[i][j] + helper(i-1, j, triangle, dp);
        int way2 = triangle[i][j] + helper(i-1, j-1, triangle, dp);

        return dp[i][j] = min(way1, way2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for (int i = 0; i < n; i++){
            res = min(res, helper(n-1, i, triangle, dp));
        }
        return res;
    }
};