class Solution {
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[r][c] = true;

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];

            if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid[0].size()) continue;
            if (!visited[rr][cc] && grid[rr][cc] == '1'){
                dfs(rr, cc, grid, visited);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, visited);
                    res++;
                }
            }
        }
        return res;
    }
};