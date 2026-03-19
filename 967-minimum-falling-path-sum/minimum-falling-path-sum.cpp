class Solution {
    /*int helper(int i, int j, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp){
        if (i == 0 && j >=  0 && j < n) return matrix[i][j];
        if (i < 0 || j < 0 || j >= n || i >= n) return 1e5;
        if (dp[i][j] != -101) return dp[i][j];
        int ld = matrix[i][j] + helper(i-1, j-1, matrix, n, dp);
        int rd = matrix[i][j] + helper(i-1, j+1, matrix, n, dp);
        int up = matrix[i][j] + helper(i-1, j, matrix, n, dp);

        return dp[i][j] = min(min(ld, rd), up);
    }*/
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp (n, vector<int> (n, -101));
        /*int res = 1e9;
        for (int i = 0; i < n; i++){
            res = min(res, helper(n-1, i, matrix, n, dp));
        }
        return res;*/

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == 0) dp[i][j] = matrix[i][j];
                else{
                    int ld = 1e5, rd = 1e5, up = 1e5;
                    if (i-1 >= 0 && j-1 >= 0) ld = matrix[i][j] + dp[i-1][j-1];
                    if (i-1 >= 0 && j+1 < n) rd = matrix[i][j] + dp[i-1][j+1];
                    if (i-1 >=0) up = matrix[i][j] + dp[i-1][j];

                    dp[i][j] =  min(min(ld, rd), up);
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};