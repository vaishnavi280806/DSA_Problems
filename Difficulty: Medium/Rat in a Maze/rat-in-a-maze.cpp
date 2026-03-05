class Solution {
    char dir(int r, int c){
        if (r == -1 && c == 0) return 'U';
        else if (r == 0 && c == -1) return 'L';
        else if (r == 0 && c == 1) return 'R';
        else return 'D';
    }
    void helper(vector<vector<int>>& maze, int r, int c, string& ds, vector<string>& res, vector<vector<int>>& visited){
        if (r == maze.size() - 1 && c == maze.size() - 1){
            res.push_back(ds);
            return;
        }
        vector<int> row = {1, 0, 0, -1};
        vector<int> col = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++){
            int rr = r + row[i];
            int cc = c + col[i];
            if (rr < 0 || rr >= maze.size() || cc < 0 || cc >= maze.size()) continue;
            if (maze[rr][cc] != 0 && visited[rr][cc] == 0){
                ds.push_back(dir(row[i], col[i]));
                visited[rr][cc] = 1;
                helper(maze, rr, cc, ds, res, visited);
                ds.pop_back();
                visited[rr][cc] = 0;
            }
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        string ds;
        vector<vector<int>> visited (maze.size(), vector<int> (maze.size(), 0));
        visited[0][0] = 1;
        vector<string> res;
        helper(maze, 0, 0, ds, res, visited);
        return res;
    }
};