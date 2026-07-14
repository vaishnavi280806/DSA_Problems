class Solution {
    int helper(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(amt == 0) return 1;
        if (amt < 0 || idx < 0) return 0;
        if (dp[idx][amt] != -1) return dp[idx][amt];

        int pick = helper(idx, amt - coins[idx], coins, dp);
        int notpick = helper(idx-1, amt, coins, dp);

        return dp[idx][amt] = pick + notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return helper(n-1, amount, coins, dp);
    }
};