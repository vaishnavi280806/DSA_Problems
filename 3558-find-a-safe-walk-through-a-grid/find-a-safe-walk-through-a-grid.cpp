class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        queue<pair<int, pair<int, int>>> q;
        q.push({health - grid[0][0], {0, 0}});
        vector<vector<int>> dist(m, vector<int>(n, INT_MIN));
        dist[0][0] = health - grid[0][0];

        while (!q.empty()) {
            int h =q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (r == m - 1 && c == n - 1 && h >= 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue;
                if (h - grid[rr][cc] >= 1 && dist[rr][cc] < h - grid[rr][cc]) {
                    dist[rr][cc] = h - grid[rr][cc];
                    q.push({h - grid[rr][cc], {rr, cc}});
                }
            }
        }
        
        return false;
    }
};