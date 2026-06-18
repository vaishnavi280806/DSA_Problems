class Solution {
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;
        
        for (int x : graph[node]){
            if (!visited[x]){
                if (dfs(x, node, graph, visited)) return true;;
            }
            else{
                if (x != parent) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        
        for (auto &e: edges){
            int u = e[0];
            int v = e[1];
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                if (dfs(i, -1, graph, visited)) return true;
            }
        }
        return false;
    }
};