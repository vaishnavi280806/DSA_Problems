class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        deque<pair<int, int>> dq;
        dq.push_back({0, 0});

        while (!dq.empty()){
            int r = dq.front().first;
            int c = dq.front().second;
            dq.pop_front();

            if (r == m-1 && c == n-1) return dist[r][c];

            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue;
                if (grid[rr][cc] == 0 &&  dist[r][c] < dist[rr][cc]){
                    dist[rr][cc] = dist[r][c];
                    dq.push_front({rr, cc});
                }
                else if (grid[rr][cc] == 1 &&  dist[r][c] + 1 < dist[rr][cc]){
                    dist[rr][cc] = dist[r][c] + 1;
                    dq.push_back({rr, cc});
                }
            }
        }
        return dist[m-1][n-1];
        return -1;
    }
};