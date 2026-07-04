class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto it : roads){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({INT_MAX, 1});
        
        while (!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            cout << node;
            pq.pop();

            for (auto it : graph[node]){
                int adjN = it.first;
                int adjW = it.second;

                if (adjW < wt && adjW < dist[adjN]){
                    dist[adjN] = adjW;
                    pq.push({adjW, adjN});
                }
                else if (adjW >= wt && wt < dist[adjN]){
                    dist[adjN] = wt;
                    pq.push({wt, adjN});
                }
            }
        }
        return dist[n];
    }
};