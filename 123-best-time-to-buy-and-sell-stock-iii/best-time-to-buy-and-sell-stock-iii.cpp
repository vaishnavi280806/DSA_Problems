class Solution {
    /*helper(int idx, int buy, int rem, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if (idx == prices.size()) return 0;
        if (rem == 0) return 0;
        if (dp[idx][buy][rem] != -1) return dp[idx][buy][rem];
        int profit = 0;
        if (buy){
            profit = max(-prices[idx] + helper(idx+1, 0, rem, prices, dp), helper(idx+1, 1, rem, prices, dp));
        }
        else{
            profit = max(prices[idx] + helper(idx+1, 1, rem-1, prices, dp), helper(idx+1, 0, rem, prices, dp));
        }
        return dp[idx][buy][rem] = profit;
    }*/
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
        //return helper(0, 1, 2, prices, dp);

        for (int idx = n; idx >= 0; idx--){
            for (int buy = 0; buy < 2; buy++){
                for (int rem = 0; rem < 3; rem++){
                    if (idx == n) dp[idx][buy][rem] = 0;
                    else if (rem == 0) dp[idx][buy][rem] = 0;
                    else{
                        int profit = 0;
                        if (buy){
                            profit = max(-prices[idx] + dp[idx+1][0][rem], dp[idx+1][1][rem]);
                        }
                        else{
                            profit = max(prices[idx] + dp[idx+1][1][rem-1], dp[idx+1][0][rem]);
                        }
                        dp[idx][buy][rem] = profit;
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};