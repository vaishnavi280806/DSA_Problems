class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int> (3, 0));
        for (int idx = n; idx >= 0; idx--){
            vector<vector<int>> temp(2, vector<int> (3, 0));
            for (int buy = 0; buy < 2; buy++){
                for (int rem = 0; rem < 3; rem++){
                    if (idx == n) temp[buy][rem] = 0;
                    else if (rem == 0) temp[buy][rem] = 0;
                    else{
                        int profit = 0;
                        if (buy){
                            profit = max(-prices[idx] + prev[0][rem], prev[1][rem]);
                        }
                        else{
                            profit = max(prices[idx] + prev[1][rem-1], prev[0][rem]);
                        }
                        temp[buy][rem] = profit;
                    }
                }
            }
            prev = temp;
        }
        return prev[1][2];
    }
};