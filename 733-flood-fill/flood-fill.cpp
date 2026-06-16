class Solution {
    vector<int> dr = {-1, 0, 0, 1};
    vector<int> dc = {0, -1, 1, 0};
    void dfs(int r, int c, vector<vector<int>>& image, vector<vector<bool>>& visited, int color, int start){
        visited[r][c] = true;
        image[r][c] = color;

        for (int i = 0; i < 4; i++){
            int rr = r + dr[i];
            int cc = c + dc[i];

            if (rr < 0 || rr >= image.size() || cc < 0 || cc >= image[0].size()) continue;
            if (!visited[rr][cc] && image[rr][cc] == start) dfs(rr, cc, image, visited, color, start);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int start = image[sr][sc];
        if (start == color) return image;
        dfs(sr, sc, image, visited, color, start);
        return image;
    }
};