class Solution {
    void dfs(int node, vector<int>& visited, vector<vector<int>>& graph){
        visited[node] = 1;

        for (int i = 0; i < graph.size(); i++){
            if (graph[node][i] == 1 && !visited[i]) dfs(i, visited, graph);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int res = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                cout << i;
                dfs(i, visited, isConnected);
                res++;
            }
        }
        return res;
    }
};