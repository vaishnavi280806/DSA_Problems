class Solution {
	public:
	vector<int> shortestPath(int V, int E, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> > graph(V);
		vector<int> indegree(V, 0);
		for (int i = 0; i < E; i++) {
			graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
			indegree[edges[i][1]]++;
		}
		
		vector<int> res(V, -1);
		vector<int> topo;
		
		queue<int> q;
		for (int i = 0; i < V; i++){
		    if (indegree[i] == 0){
		        q.push(i);
		        topo.push_back(i);
		    }
		}
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			for (auto x : graph[node]) {
				if (--indegree[x.first] == 0) {
					q.push(x.first);
					topo.push_back(x.first);
				}
			}
		}
		res[0] = 0;
		
		for (int i : topo) {
			
			for (int j = 0; j < graph[i].size(); j++) {
				int node = graph[i][j].first;
				int wt = graph[i][j].second;
				
				if (res[i] != -1 && (res[node] == -1 || res[i] + wt < res[node]))
					res[node] = res[i] + wt;
			}
		}
		
		return res;
	}
};
