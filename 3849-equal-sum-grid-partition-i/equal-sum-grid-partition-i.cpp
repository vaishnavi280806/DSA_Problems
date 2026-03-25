class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> prefix(m + 1, vector<long long> (n + 1, 0));
        
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                prefix[i][j] = grid[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            }
        }

        for (int i = 1; i < m; i++){
            if (prefix[i][n] == prefix[m][n] - prefix[i][n]) return true;
        }

        for (int i = 1; i < n; i++){
            if (prefix[m][i] == prefix[m][n] - prefix[m][i]) return true;
        }
        return false;
    }
};