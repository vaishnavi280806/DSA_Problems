class Solution {
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++){
            int cost = (cuts[j+1] - cuts[i-1]) + helper(i, k-1, cuts, dp) + helper(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+1, vector<int> (cuts.size()+1, -1));
        return helper(1, cuts.size() - 2, cuts, dp);
    }
};