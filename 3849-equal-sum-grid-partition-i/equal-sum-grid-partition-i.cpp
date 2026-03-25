class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        /*vector<vector<long long>> prefix(m + 1, vector<long long> (n + 1, 0));
        
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
        return false;*/

        vector<long long> row(m, 0), col(n, 0);
        long long total = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                row[i] +=  grid[i][j];
                col[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        if (total % 2) return false;

        for (int i = 0; i < m; i++){
            if (total / 2 == row[i]) return true;
            if (i != m-1) row[i+1] += row[i];
        }

        for (int i = 0; i < n; i++){
            if (total / 2 == col[i]) return true;
            if (i != n-1) col[i+1] += col[i];
        }

        return false;

    }
};