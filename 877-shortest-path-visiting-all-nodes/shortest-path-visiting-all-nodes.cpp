class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<pair<int, int>> st; //node, mask
        queue<pair<int, pair<int, int>>> q; //node, {dis, mask}
        for (int i = 0; i < graph.size(); i++){

            q.push({i, {0, 1 << i}});
            st.insert({i, 1 << i});
        }

        while (!q.empty()){
            auto tp = q.front();
            q.pop();

            int node = tp.first;
            int dis = tp.second.first;
            int mask = tp.second.second;

            if (mask == (1 << n) - 1) return dis;

            for (int adj : graph[node]){
                int cur_mask = mask | (1 << adj);
                if (!st.count({adj, cur_mask})){
                    q.push({adj, {dis+1, cur_mask}});
                    st.insert({adj, cur_mask});
                }
            }
        }
        return 0;
    }
};