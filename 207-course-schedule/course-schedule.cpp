class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto x : pre){
            graph[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();

            for (int x : graph[node]){
                if (--indegree[x] == 0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        if (res.size() == n) return true;
        return false;
    }
};