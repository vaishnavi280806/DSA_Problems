class Solution {
    void helper(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& res){
        visited[node] = 1;
        res.push_back(node);
        
        for (int x : adj[node]){
            if (!visited[x]){
                visited[x] = 1;
                helper(x, visited, adj, res);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> res;
        helper(0, visited, adj, res);
        return res;
    }
};