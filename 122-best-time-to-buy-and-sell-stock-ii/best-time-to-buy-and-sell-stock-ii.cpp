class Solution {
    /*int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if (idx == prices.size()) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy){
            profit = max(-prices[idx] + helper(idx + 1, 0, prices, dp), helper(idx + 1, 1, prices, dp));
        }
        else{
            profit = max(prices[idx] + helper(idx + 1, 1, prices, dp), helper(idx + 1, 0, prices, dp));
        }
        return dp[idx][buy] = profit;
    }*/
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp (n+1, vector<int> (2, -1));
        //return helper(0, 1, prices, dp);

        /*for (int idx = n; idx >= 0; idx--){
            for (int buy = 1; buy >= 0; buy--){
                if (idx == n){
                    dp[idx][0] = 0;
                    dp[idx][1] = 0;
                    continue;
                }
                int profit = 0;
                if (buy){
                    profit = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
                }
                else{
                    profit = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
                }
                dp[idx][buy] = profit;
            }
        }

        return dp[0][1];*/

        vector<int> prev(2, 0);
        for (int idx = n; idx >= 0; idx--){
            vector<int> temp(2, 0);
            for (int buy = 1; buy >= 0; buy--){
                if (idx == n){
                    temp[0] = 0;
                    temp[1] = 0;
                    continue;
                }
                int profit = 0;
                if (buy){
                    profit = max(-prices[idx] + prev[0], prev[1]);
                }
                else{
                    profit = max(prices[idx] + prev[1], prev[0]);
                }
                temp[buy] = profit;
            }
            prev = temp;
        }

        return prev[1];
    }
};