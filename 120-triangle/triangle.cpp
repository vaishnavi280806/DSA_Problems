class Solution {
    /*int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if (i == 0 && j == 0) return triangle[0][0];
        if (j < 0 || j > i) return 1e5;
        if (dp[i][j] != -1) return dp[i][j];
        int way1 = triangle[i][j] + helper(i-1, j, triangle, dp);
        int way2 = triangle[i][j] + helper(i-1, j-1, triangle, dp);

        return dp[i][j] = min(way1, way2);
    }*/
   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int res = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        /*for (int i = 0; i < n; i++){
            res = min(res, helper(n-1, i, triangle, dp));
        }
        return res;*/

        for (int i = 0; i < n; i++){
            for (int j = 0; j < i+1; j++){
                if (i == 0 && j == 0) dp[i][j] = triangle[i][j];
                else{
                    int way1 = 1e9, way2 = 1e9;
                    if (i-1 >= 0){
                        if (j < i) way1 = triangle[i][j] + dp[i-1][j];
                        if (j-1 >= 0) way2 = triangle[i][j] + dp[i-1][j-1];
                    }
                    dp[i][j] = min(way1, way2);
                }
            } 
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};