class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 0;
        pq.push({grid[0][0], {0, 0}});

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};
        while (!pq.empty()){
            int t = pq.top().first;
            auto cur = pq.top().second;
            pq.pop();

            if (cur.first == n-1 && cur.second == n-1) return t;

            for (int i = 0; i < 4; i++){
                int rr = cur.first + dr[i];
                int cc = cur.second + dc[i];

                if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

                if (grid[rr][cc] <= t && t < dist[rr][cc]){
                    dist[rr][cc] = t;
                    pq.push({t, {rr, cc}});
                }
                else if (grid[rr][cc] > t && grid[rr][cc] < dist[rr][cc]){
                    dist[rr][cc] = grid[rr][cc];
                    pq.push({grid[rr][cc], {rr, cc}});
                }


            }
        }
        return dist[n-1][n-1];
        return -1;
    }
};