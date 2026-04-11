class Solution {
    int helper(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        if (i < 0  && j < 0) return 0;
        if (i < 0) return j+1;
        if (j < 0) return i+1;
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]) return dp[i][j] = helper(i-1, j-1, word1, word2, dp);
        else{
            int way1 = 1 + helper(i-1, j-1, word1, word2, dp);
            int way2 = 1 + helper(i-1, j, word1, word2, dp);
            int way3 = 1 + helper(i, j-1, word1, word2, dp);

            return dp[i][j] = min(way1, min(way2, way3));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return helper(n1-1, n2-1, word1, word2, dp);
    }
};