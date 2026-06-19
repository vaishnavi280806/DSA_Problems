class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++){
            for (auto it : graph[i]){
                rev[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> res;
        queue<int> q;
        
        for (int i = 0; i < n; i++){
            if (indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int x : rev[node]){
                if (--indegree[x] == 0){
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;;
    }
};