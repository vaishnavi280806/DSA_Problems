class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& stk){
        visited[node] = true;
        
        for (int it : graph[node]){
            if (!visited[it]) dfs(it, graph, visited, stk);
        }
        stk.push(node);
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        vector<vector<int>> rev(V);
        
        for (auto it : edges){
            graph[it[0]].push_back(it[1]);
            rev[it[1]].push_back(it[0]);
        }
        
        stack<int> stk;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) if (!visited[i]) dfs(i, graph, visited, stk);
        
        int cnt = 0;
        for (int i = 0; i < V; i++) visited[i] = false;
        stack<int> st;
        while (!stk.empty()){
            if (!visited[stk.top()]){
                dfs(stk.top(), rev, visited, st);
                cnt++;
            }
            stk.pop();
        }
        return cnt;
    }
};