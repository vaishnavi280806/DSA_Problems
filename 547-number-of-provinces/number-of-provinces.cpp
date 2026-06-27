class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v)
            return;

        if (rank[ult_u] < rank[ult_v])
            parent[ult_u] = ult_v;
        else if (rank[ult_v] < rank[ult_u])
            parent[ult_v] = ult_u;
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<pair<int, int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j])
                    edges.push_back({i, j});
            }
        }

        int res = 0;
        DisjointSet ds(n);
        for (auto it : edges) {
            int u = it.first;
            int v = it.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionByRank(u, v);
            }
        }
        for (int i = 0; i <= n; i++){
            if (ds.findUPar(i) == i) res++;
        }
        return res;
    }
};