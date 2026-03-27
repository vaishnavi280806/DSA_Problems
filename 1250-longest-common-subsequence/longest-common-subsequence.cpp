class Solution {
    /*int helper(int idx1, int idx2, string& text1, string &text2, vector<vector<int>>& dp){
        if (idx1 < 0 || idx2 < 0) return 0;
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if (text1[idx1] == text2[idx2]) return dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, text1, text2, dp);
        return dp[idx1][idx2] = max(helper(idx1 - 1, idx2, text1, text2, dp), helper(idx1, idx2 - 1, text1, text2, dp));
    }*/
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        //vector<vector<int>> dp(n1, vector<int> (n2, -1));
        //return helper(n1-1, n2-1, text1, text2, dp);

        //shifting of index
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));

        for (int i = 0; i <= n1; i++){
            for (int j = 0; j <= n2; j++){
                if (i == 0) dp[i][j] = 0;
                else if (j == 0) dp[i][j] = 0;
                else{
                    if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};