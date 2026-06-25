class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        while (!pq.empty()){
            int diff = pq.top().first;
            auto cur = pq.top().second;
            pq.pop();

            if (cur.first == m-1 && cur.second == n-1) return diff;

            for (int i = 0; i < 4; i++){
                int rr = cur.first + dr[i];
                int cc = cur.second + dc[i];

                if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue;
                int newd = abs(heights[rr][cc] - heights[cur.first][cur.second]);
                if (newd > diff && newd < dist[rr][cc]){
                    dist[rr][cc] = newd;
                    pq.push({newd, {rr, cc}});
                }
                else if (newd <= diff && diff < dist[rr][cc]){
                    dist[rr][cc] = diff;
                    pq.push({diff, {rr, cc}});
                }
            }
        }
        return -1;        
    }
};