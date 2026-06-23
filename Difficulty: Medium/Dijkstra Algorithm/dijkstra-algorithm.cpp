class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>>  graph(V);
        
        for (auto x : edges){
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        while (!pq.empty()){
            auto node = pq.top();
            pq.pop();
            
            for (auto x : graph[node.second]){
                if (node.first + x.second < dist[x.first]){
                    dist[x.first] = node.first + x.second;
                    pq.push({dist[x.first], x.first});
                }
            }
        }
        
        return dist;
    }
};