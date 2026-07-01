class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        vector<vector<int>> newg(n,  vector<int> (n, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++){
            for (int j  =0; j < n; j++){
                if (grid[i][j] == 1){
                    q.push({i, j});
                    newg[i][j] = 0;
                }
            }
        }
       
        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};
        while (!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
                if (newg[rr][cc] > 1 + newg[r][c]){
                    newg[rr][cc] = 1 + newg[r][c];
                    q.push({rr, cc});
                }
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << newg[i][j] << " ";
            }
            cout << endl;
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({newg[0][0], {0, 0}});

        vector<vector<int>> dist(n, vector<int> (n,INT_MIN));
        dist[0][0] = newg[0][0];

        while (!pq.empty()){
            int sf = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n-1 && c == n-1) return sf;

            for (int i = 0; i < 4; i++){
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

                if (min(sf, newg[rr][cc]) > dist[rr][cc]){
                    dist[rr][cc] = min(sf, newg[rr][cc]);
                    pq.push({dist[rr][cc], {rr, cc}});
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        return -1;


    }
};