class Solution {
    int helper(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(amt == 0) return 0;
        if (amt < 0 || idx < 0) return 1e9;
        if (dp[idx][amt] != -1) return dp[idx][amt];

        long long pick = 1 + helper(idx, amt - coins[idx], coins, dp);
        long long notpick = helper(idx-1, amt, coins, dp);

        return dp[idx][amt] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, - 1));
        int res = helper(n-1, amount, coins, dp);
        if (res == 1e9) return -1;
        return res;
    }
};