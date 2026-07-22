class Solution {
    int helper(int pos, int mask, int n, vector<vector<int>>& dp){
        if(pos == n+1) return 1;
        if (dp[pos][mask] != -1) return dp[pos][mask];

        int res = 0;
        for(int i = 1; i <= n; i++){
            if ((mask & (1 << i)) == 0) if(i % pos == 0 || pos % i == 0) res += helper(pos+1, mask | (1 << i), n, dp);
        }
        return dp[pos][mask]= res;
    }
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(n+1, vector<int> (1 << (n+1), -1));
        return helper(1, 0, n, dp);
    }
};