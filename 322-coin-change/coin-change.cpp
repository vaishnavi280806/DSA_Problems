class Solution {
    long long helper(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if (amt == 0) return 0;
        if (idx < 0) return INT_MAX;
        if (dp[idx][amt] != -1) return dp[idx][amt];
        long long pick = INT_MAX;
        if (coins[idx] <= amt) pick = 1 + helper(idx, amt - coins[idx], coins, dp);
        long long notpick = helper(idx - 1, amt, coins, dp);

        return dp[idx][amt] = min(pick, notpick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1, -1));
        int ans = helper(n-1, amount, coins, dp);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};