class DisjointSet {
    public:
        vector<int> rank, parent;

        DisjointSet(int n){
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i <n; i++) parent[i] = i;
        }

        int findUPar(int node){
            if (node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionR(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
            else{
                rank[ulp_u]++;
                parent[ulp_v] = ulp_u;
            }
           
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for (auto it : connections){
            int u = it[0];
            int v = it[1];

            if (ds.findUPar(u) == ds.findUPar(v)){
                extra++;
            }
            else{
                ds.unionR(u, v);
            }
        }

        int comp = 0;
        for (int i = 0; i < n; i++){
            if (ds.findUPar(i) == i) comp++;
        }

        if (extra >= comp - 1) return comp-1;
        return -1;
    }
};