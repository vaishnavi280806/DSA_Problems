class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph (n);

        for (auto it : flights){
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<vector<int>> q;
        q.push({0, src, 0}); //stops, node, price

        while (!q.empty()){
            int stops = q.front()[0];
            int node = q.front()[1];
            int price = q.front()[2];
            q.pop();

            for (auto adj : graph[node]){
                if (price + adj.second < dist[adj.first] && stops <= k){
                    dist[adj.first] = adj.second + price;
                    q.push({stops + 1, adj.first, dist[adj.first]});
                }
            }


        }
        if (dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};