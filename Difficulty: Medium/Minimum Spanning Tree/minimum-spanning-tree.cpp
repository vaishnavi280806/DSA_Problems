class DisjointSet{
    vector<int> rank, parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            
            for (int i = 0; i <= n; i++) parent[i] = i;
        }
        
        int findUPar(int node){
            if (parent[node] == node) return node;
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank (int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            
            if (ulp_u  == ulp_v) return;
            
            if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
            else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

class Solution {
    static bool compare(vector<int> a, vector<int> b){
        return a[2] < b[2];
    }
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), compare);
        
        int res = 0;
        
        DisjointSet ds(V);
        
        for (auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if (ds.findUPar(u) != ds.findUPar(v)){
                res += wt;
                ds.unionByRank(u, v);
            }
        }
        return res;
    }
};