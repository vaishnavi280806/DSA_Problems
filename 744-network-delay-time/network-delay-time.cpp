class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto it : times){
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto adj : graph[node]){
                if (time + adj.second < dist[adj.first]){
                    dist[adj.first] = time + adj.second;
                    pq.push({dist[adj.first], adj.first});
                }
            }
        }
        //for (int i = 0; i < n+1; i++) cout << dist[i] << " ";
        int res = *max_element(dist.begin(), dist.end());

        if (res == INT_MAX) return -1;
        return res;
    }
};