class Solution {
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp, int fee){
        if (idx == prices.size()) return 0;
        if (dp[idx][buy] != -1) return dp[idx][buy];
        int profit = 0;
        if (buy){
            profit = max(-prices[idx] + helper(idx + 1, 0, prices, dp, fee), helper(idx + 1, 1, prices, dp, fee));
        }
        else{
            profit = max(prices[idx] + helper(idx + 1, 1, prices, dp, fee) - fee, helper(idx + 1, 0, prices, dp, fee));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int> (2, -1));
        return helper(0, 1, prices, dp, fee);
    }
};