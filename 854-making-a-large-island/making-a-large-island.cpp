class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionS(int u, int v) {
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if (ult_u == ult_v)
            return;

        if (size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};
        int flag = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    for (int i = 0; i < 4; i++) {
                        int rr = r + dr[i];
                        int cc = c + dc[i];

                        if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
                        if (grid[rr][cc] == 1 && ds.findUPar(rr * n + cc) != ds.findUPar(r * n + c)){
                            ds.unionS(rr * n + cc, r * n + c);
                        }
                    }
                }
                else flag = 1;
            }
        }
        if (flag == 0) return n*n;
        
        int res = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < n; c++){
                unordered_set<int> st;
                int cnt = 0;
                if (grid[r][c] == 0){
                    for (int i = 0; i < 4; i++) {
                        int rr = r + dr[i];
                        int cc = c + dc[i];

                        if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;
                        if (grid[rr][cc] == 1) st.insert(ds.findUPar(rr * n + cc));
                    }
                    for (int it : st) cnt += ds.size[it];
                    res = max(res, cnt + 1);

                }
            }
        }
        return res;
    }
};