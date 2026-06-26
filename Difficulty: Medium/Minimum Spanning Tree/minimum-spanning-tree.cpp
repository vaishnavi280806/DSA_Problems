class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V);
        
        for (auto it : edges){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> visited(V, 0);
        
        pq.push({0, 0, -1}); //wt, node, parent
        int res = 0;
        
        while (!pq.empty()){
            int wt = pq.top()[0];
            int node = pq.top()[1];
            int par = pq.top()[2];
            
            pq.pop();
            
            if (!visited[node]) res += wt;
            
            visited[node] = 1;
            
            for (auto adj : graph[node]){
                if (!visited[adj.first]) pq.push({adj.second, adj.first});
            }
            
        }
        
        return res;
    }
};