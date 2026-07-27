class DSU{
public:
    vector<int> parent, rank;
    DSU (int n){
        rank.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find (int node){
        if (node == parent[node]) return node;
        else return parent[node] = find(parent[node]);
    }

    void unionR(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if (rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra = 0;

        for (auto it : connections){
            int u = it[0];
            int v = it[1];

            if (dsu.find(u) == dsu.find(v)) extra++;
            else dsu.unionR(u, v);
        }

        int comp = 0;
        for (int i = 0; i < n; i++){
            if (dsu.find(i) == i) comp++;
        }

        if (extra >= comp-1) return comp-1;
        return -1;
    }
};