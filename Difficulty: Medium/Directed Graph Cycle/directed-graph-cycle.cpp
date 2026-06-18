class Solution {
    bool dfs(int node, int parent, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathV){
        visited[node] = true;
        pathV[node] = true;
        
        for (int x : graph[node]){
            if (!visited[x]){
                if (dfs(x, node, graph, visited, pathV)) return true;;
            }
            else{
                if (pathV[x]) return true;
            }
        }
        pathV[node] = false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        
        for (auto &e: edges){
            int u = e[0];
            int v = e[1];
            
            graph[u].push_back(v);
        }
        vector<bool> visited(V, false);
        vector<bool> pathV(V, false);
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                if (dfs(i, -1, graph, visited, pathV)) return true;
            }
        }
        return false;
    }
};