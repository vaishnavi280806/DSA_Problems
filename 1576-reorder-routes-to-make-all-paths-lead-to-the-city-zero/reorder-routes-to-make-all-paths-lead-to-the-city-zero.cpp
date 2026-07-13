class Solution {
    void dfs(int node, vector<vector<int>>& graph, set<vector<int>>& clone, vector<int>& visited, int& cnt){
        visited[node] = true;

        for (int it : graph[node]){
            if (!visited[it]){
                if (clone.count({node, it})) cnt++;
                dfs(it, graph, clone, visited, cnt);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<vector<int>> clone;
        vector<vector<int>> graph(n);

        for (auto it : connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);

            clone.insert(it);
        }

        vector<int> visited(n, 0);
        int cnt = 0;
        dfs(0, graph, clone, visited, cnt);
        return cnt;


    }
};