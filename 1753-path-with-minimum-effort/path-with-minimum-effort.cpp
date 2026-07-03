class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        dist[0][0] = 0;

        while (!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == m-1 && c == n-1) return diff;

            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= m || cc < 0 || cc >= n) continue;
                int newd = abs(heights[rr][cc] - heights[r][c]);

                if (diff < newd && newd < dist[rr][cc]){
                    pq.push({newd, {rr, cc}});
                    dist[rr][cc] = newd;
                }
                else if (diff >= newd && diff < dist[rr][cc]){
                    pq.push({diff, {rr, cc}});
                    dist[rr][cc] = diff;
                }
            }
        }
        return -1;
    }
};