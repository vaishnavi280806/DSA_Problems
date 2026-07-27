class Solution{
    int helper(int r, int c, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        if (r >= dungeon.size() || c >= dungeon[0].size()) return 1e8;
        if (r == dungeon.size() -1 && c == dungeon[0].size() - 1) return max(1, 1 - dungeon[r][c]);

        if (dp[r][c] != -1) return dp[r][c];

        int up = helper(r+1, c, dungeon, dp);
        int left = helper(r, c+1, dungeon, dp);

        int need = min(up, left);
        return dp[r][c] = max(1, need - dungeon[r][c]);
        
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> dp(dungeon.size(), vector<int> (dungeon[0].size(), -1));
        return helper(0, 0, dungeon, dp);
    }
};