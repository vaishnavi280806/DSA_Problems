class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        q.push(0);
        int n = adj.size();
        vector<int> visited(n, 0);
        vector<int> res;
        visited[0] = 1;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int x : adj[node]){
                if (!visited[x]){
                    q.push(x);
                    visited[x] = 1;
                }
            }
            
        }
        return res;
    }
};