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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxR = 0;
        int maxC = 0;
        for (auto it : stones){
            maxR = max(it[0], maxR);
            maxC = max(it[1], maxC);
        }
        DisjointSet ds(maxR + maxC + 2);
        unordered_set <int> hash;
        for (int i = 0; i < n; i++){
            ds.unionR(stones[i][0], stones[i][1] + maxR + 1);
            hash.insert(stones[i][0]);
            hash.insert(stones[i][1] + maxR + 1);
        }
        int comp = 0;
        for (int i = 0; i < maxR + maxC + 2; i++){
            if (hash.count(i) && ds.findUPar(i) == i) comp++;
        }
        return n - comp;
    }
};