class Solution {
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& board){
        visited[r][c] = true;
        board[r][c] = 1;

        for (int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];

            if (rr < 0 || rr>= board.size() || cc < 0 || cc>= board[0].size()) continue;

            if (!visited[rr][cc] && board[rr][cc] == 2) dfs(rr, cc, visited, board);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 1) board[i][j] = 2;
            }
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (!visited[i][j] && (i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 2){
                    dfs(i, j, visited, board);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 2){
                    board[i][j] = 1;
                    res++;
                }
            }
        }
        return res;
    }
};