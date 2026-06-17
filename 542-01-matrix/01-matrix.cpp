class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        vector<vector<int>> res(m, vector<int> (n, 0));

        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue;
                if (!visited[rr][cc] && mat[rr][cc] == 1){
                    visited[rr][cc] = true;
                    q.push({{rr, cc}, d+1});
                    res[rr][cc] = d + 1;
                }
            }
        }
        return res;
    }
};