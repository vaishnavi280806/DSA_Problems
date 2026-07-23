class Solution {
    int mod = 1e9 + 7;
    int helper(int hat, int mask, vector<unordered_set<int>>& hats, int n, vector<vector<int>>& dp){
        if (hat == 41) return mask == (1 << n) - 1;
        if (dp[hat][mask] != -1) return dp[hat][mask];

        int cnt = helper(hat+1, mask, hats, n, dp) % mod;;
        for (int i = 0; i < n; i++){
            if ((mask & (1 << i)) == 0){
                if (hats[i].count(hat)) cnt = (cnt % mod + helper(hat+1, (mask | (1 << i)), hats, n, dp) % mod) % mod;
            }
        }
        return dp[hat][mask] = cnt % mod;

    }
public:
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        vector<vector<int>> dp(41, vector<int> ((1 << n), -1));
        vector<unordered_set<int>> mp(n);

        for (int i = 0; i < n; i++){
            for (int it : hats[i]) mp[i].insert(it);
        }

        return helper(1, 0, mp, n,dp);
    }
};