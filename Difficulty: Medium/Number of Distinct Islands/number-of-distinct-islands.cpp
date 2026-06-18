class Solution {
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    void dfs(int r, int c, vector<pair<int, int>>& shape, vector<vector<char>>& grid, vector<vector<bool>>& visited, int sr, int sc){
        visited[r][c] = true;
        
        for (int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            
            if (rr < 0 || rr >= grid.size() || cc < 0 || cc >= grid[0].size()) continue;
            if (!visited[rr][cc] && grid[rr][cc] == 'L'){
                shape.push_back({rr-sr, cc-sc});
                dfs(rr, cc, shape, grid, visited, sr, sc);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        set<vector<pair<int, int>>> hash;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                
                if (!visited[i][j] && grid[i][j] == 'L'){
                    vector<pair<int, int>> shape;
                    dfs(i, j, shape, grid, visited, i, j);
                    hash.insert(shape);
                }
            }
        }
        return hash.size();
    }
};
