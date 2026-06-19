class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        vector<int> indegree(V, 0);
        for (auto it : edges){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int> res;
        queue<int> q;
        
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int x : graph[node]){
                if (--indegree[x] == 0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        if (res.size() != V) return true;
        return false;
    }
};