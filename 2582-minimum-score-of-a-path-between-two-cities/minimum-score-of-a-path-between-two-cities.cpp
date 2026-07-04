class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto it : roads){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(1);
        visited[1] = true;
        int res = INT_MAX;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (auto it : graph[node]){
                int adjN = it.first;
                int adjW = it.second;

                res = min(res, adjW);

                if (!visited[adjN]){
                    q.push(adjN);
                    visited[adjN] = true;
                }
            }
        }
        return res;
    }
};