class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for (int i = 1; i <= V; i++){
            for(int j = 0; j < edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    if (i == V) return {-1};
                }
            }
        }
        return dist;
    }
};
