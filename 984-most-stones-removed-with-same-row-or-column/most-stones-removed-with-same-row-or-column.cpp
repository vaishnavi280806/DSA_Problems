class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node] = true;

        for (int it : graph[node]){
            if (!visited[it]){
                dfs(it, graph, visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n);

        int comp = 0;
        for (int i = 0; i < graph.size(); i++){
            if (!visited[i]){
                dfs(i, graph, visited);
                comp++;
            }
        }
        cout << comp;
        return n - comp;
    }
};