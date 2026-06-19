class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& path, unordered_set<int>& res){
        visited[node] = true;
        path[node] = true;

        for (int x : graph[node]){
            if (!visited[x]){
                if (dfs(x, graph, visited, path, res)){
                    return true;
                }
            }
            else{
                if (path[x]){
                    return true;
                }
            }
        }
        res.insert(node);
        path[node] = false;
        return false;

    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> path(n, false);
        vector<int> ans;
        unordered_set<int> res;

        for (int i = 0; i < n; i++){
            if (!visited[i]){
                if (!dfs(i, graph, visited, path, res)) res.insert(i);
            }
        }

        for (int i = 0; i < n; i++) if (graph[i].size() == 0) res.insert(i);
        for (int x : res) ans.push_back(x);
        sort(ans.begin(), ans.end());

        return ans;
    }
};