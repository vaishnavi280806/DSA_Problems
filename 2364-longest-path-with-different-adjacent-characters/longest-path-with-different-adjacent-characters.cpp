class Solution {
    int dfs(int node, string& s, vector<vector<int>>& graph, int& ans){
        if (graph[node].size() == 0) return 1;
        int m1 = 0, m2 = 0;

        for (int it : graph[node]){
            int len = dfs(it, s, graph,  ans);
            ans = max(ans, len);

            if (s[node] == s[it]) continue;
            if (len > m1){
                m2 = m1;
                m1 = len;
            }
            else m2 = max(m2, len);
        }
        ans = max(ans, 1 + m1 + m2);
        return 1 + m1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++){
            if (parent[i] == -1) continue;
            graph[parent[i]].push_back(i);
        }

        int ans = 1;
        dfs(0, s, graph, ans);

        return ans;



    }
};