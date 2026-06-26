class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

        for (auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (dist[j][i] != INT_MAX && dist[i][k] != INT_MAX && dist[j][i] + dist[i][k] < dist[j][k]){
                        dist[j][k] = dist[j][i] + dist[i][k];
                    }
                }
            }
        }

        int res = 0;
        int mini = INT_MAX;

        for (int i = 0; i< n; i++){
            int cnt = 0;
            for (int j = 0; j < n; j++){
                if (dist[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt < mini){
                mini = cnt;
                res = i;
            }
            else if (cnt == mini) res = max(res, i);
        }
        return res;
    }
};