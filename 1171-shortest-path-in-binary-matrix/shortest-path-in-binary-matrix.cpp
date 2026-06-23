class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        //priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
        dist[0][0] = 1;

        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        while(!q.empty()){
            auto node = q.front();
            auto cur = node.second;
            int dis = node.first;
            q.pop();

            if (cur.first == n-1 && cur.second == n-1) return dis;

            for (int i = 0; i < 8; i++){
                int rr = dr[i] + cur.first;
                int cc = dc[i] + cur.second;

                if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

                if (grid[rr][cc] == 0 && dis + 1 < dist[rr][cc]){
                    dist[rr][cc] = dis + 1;
                    q.push({dist[rr][cc], {rr, cc}});
                }
            }
            
        }
        if (dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1];

    }
};