class Solution {
    int helper(int start, int end, vector<int>& piles, vector<vector<int>>& dp){
        if (start == end) return piles[start];
        if (dp[start][end] != -1) return dp[start][end];

        int first = piles[start] - helper(start+1, end, piles, dp);
        int last = piles[end] - helper(start, end-1, piles, dp);

        return dp[start][end] = max(first, last);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return helper(0, n-1, piles, dp) > 0;
    }
};