class Solution {
    /*int helper(int i, int j, string& s, vector<vector<int>>& dp){
        if (j <= i) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]){
            return dp[i][j] = helper(i+1, j-1, s, dp);
        }
        return dp[i][j] = 1 + min(helper(i+1, j, s, dp), helper(i, j-1, s, dp));
    }*/
public:
    int minInsertions(string s) {
        int n = s.size();
        //vector<vector<int>> dp(n, vector<int> (n, -1));
        //return helper(0, n-1, s, dp);

        /*vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= n; j++){
                if (j <= i) dp[i][j] = 0;
                else{
                    if (s[i-1] == s[j-1]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[1][n];*/

        vector<int> prev(n+1);
        for (int i = n; i >= 1; i--){
            vector<int> temp(n+1);
            for (int j = 1; j <= n; j++){
                if (j <= i) temp[j] = 0;
                else{
                    if (s[i-1] == s[j-1]){
                        temp[j] = prev[j-1];
                    }
                    else{
                        temp[j] = 1 + min(prev[j], temp[j-1]);
                    }
                }
            }
            prev = temp;
        }

        return prev[n];
    }
};