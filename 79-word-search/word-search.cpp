class Solution {
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    bool helper(vector<vector<char>>& board, int r, int c, int idx, string& word, vector<vector<int>>& visited){
        if (idx == word.size()) return true;
        for (int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (rr < 0 || rr >= board.size() || cc < 0 || cc >= board[0].size() || visited[rr][cc] == 1) continue;
            if (board[rr][cc] == word[idx]){
                visited[rr][cc] = 1;
                if (helper(board, rr, cc, idx + 1, word, visited)) return true;
                visited[rr][cc] = 0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 0));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    visited[i][j] = 1;
                    if (helper(board, i, j, 1, word, visited)) return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};