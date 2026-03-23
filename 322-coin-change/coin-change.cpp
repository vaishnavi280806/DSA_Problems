class Solution {
    long long helper(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if (idx == 0){
            if (amt % coins[0] == 0) return amt / coins[0];
            return INT_MAX;
        };
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
        /*for (int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        
        for (int i = 1; i < n; i++){
            for (int j = 1; j < amount+1; j++){
                long long pick = INT_MAX;
                if (coins[i] <= j) pick = 1 + dp[i][j - coins[i]];
                long long notpick = INT_MAX;
                if (i != 0) notpick = dp[i - 1][j];

                return dp[i][j] = min(pick, notpick);
            }
        }*/
        if (ans == INT_MAX) return -1;
        return ans;
    }
};