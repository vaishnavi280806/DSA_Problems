class Solution {
    bool helper(vector<vector<pair<int, int>>>& graph, vector<bool>& online, int mid, long long k){
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(online.size(), LLONG_MAX);
        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()){
            int total = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (total > k) return false;
            if (node == online.size() - 1) return true;

            for (auto it : graph[node]){
                int adjN = it.first;
                int adjC = it.second;

                //if (!online[adjN]) continue;

                if (adjC < mid) continue;
                if (dist[node] + adjC < dist[adjN]){
                    dist[adjN] = dist[node] + adjC;
                    pq.push({dist[adjN], adjN});
                }
            }
        }
        return false;
    }
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        //if (edges.size() == 0) return -1;
        vector<vector<pair<int, int>>> graph(n);
        int low = INT_MAX, high = 0;
        for (auto it : edges){
            if (!online[it[0]] || !online[it[1]]) continue;
            graph[it[0]].push_back({it[1], it[2]});
            low = min(low, it[2]);
            high = max(high, it[2]);
        }

        if (!helper(graph, online, low, k)) return -1;

        while (low <= high){
            int mid = low + (high - low)/2;

            if (helper(graph, online, mid, k)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};