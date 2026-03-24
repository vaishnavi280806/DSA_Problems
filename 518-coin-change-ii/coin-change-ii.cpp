class Solution {
    /*int helper(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if (idx == coins.size()){
            if (amt == 0) return 1;
            return 0;
        }
        if (dp[idx][amt] != -1) return dp[idx][amt];
        int pick = 0;
        if (coins[idx] <= amt) pick = helper(idx, amt - coins[idx], coins, dp);
        int notpick = helper(idx + 1, amt, coins, dp);

        return dp[idx][amt] = pick + notpick;
    }*/
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(amount+1, 0));
        //return helper(0,  amount, coins, dp);
        dp[n][0] = 1;
        for (int idx = n-1; idx >= 0; idx--){
            for (int amt = 0; amt <= amount; amt++){
                unsigned long long pick = 0;
                if (coins[idx] <= amt) pick = dp[idx][amt - coins[idx]];
                unsigned long long notpick = dp[idx + 1][amt];

                dp[idx][amt] = pick + notpick;
            }
        }
        return dp[0][amount];
    }
};