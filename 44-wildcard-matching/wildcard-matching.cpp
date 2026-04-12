class Solution {
    /*bool helper(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if (i < 0 & j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0){
            for (int k = 0; k <= j; k++){
                if (p[k] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if ((s[i] == p[j]) || p[j] == '?') return dp[i][j] = helper(i-1, j-1, s, p, dp);
        if (p[j] == '*'){
            return dp[i][j] = helper(i-1, j, s, p, dp) || helper(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    }*/
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        //vector<vector<int>> dp(m, vector<int> (n, -1));
        //return helper(m-1, n-1, s, p, dp);

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (j == 0) dp[i][j] = 0;
                else if (i == 0){
                    int flag = 0;
                    for (int k = 1; k <= j; k++){
                        if (p[k-1] != '*'){
                            dp[i][j] = 0;
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) dp[i][j] = 1;
                }
                else if ((s[i-1] == p[j-1]) || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = 0;
            }
        }
        return dp[m][n];
    }
};