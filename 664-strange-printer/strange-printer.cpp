class Solution {
    int helper(int i, int j, string& s, vector<vector<int>>& dp){
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1 + helper(i+1, j, s, dp);

        for (int k = i + 1; k <= j; k++){
            if (s[i] == s[k]){
                ans = min(ans, helper(i+1, k-1, s, dp) + helper(k, j, s, dp));
            }
        }
        return dp[i][j] = ans;
    }
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n-1, s, dp);
    }
};