class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& res){
        visited[node] = true;
        
        for (int x : graph[node]){
            if (!visited[x]) dfs(x, graph, visited, res);
        }
        res.push_back(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for (auto it : edges){
            graph[it[0]].push_back(it[1]);
        }
        vector<bool> visited(V, false);
        vector<int> res;
        
        for (int i = 0; i < V; i++){
            if (!visited[i]) dfs(i, graph, visited, res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};