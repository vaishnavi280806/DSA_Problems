class DisjointSet {
public:
    unordered_map <string, int> rank;
    unordered_map <string, string> parent;

    DisjointSet(vector<vector<string>>& accounts) {
        for (int i = 0; i < accounts.size(); i++){
            for (int j = 1; j < accounts[i].size(); j++){
                if (!rank.count(accounts[i][j])){
                    rank[accounts[i][j]] = 0;
                    parent[accounts[i][j]] = accounts[i][j];
                }
            }
        }
    }

    string findUPar(string node){
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionR(string u, string v){
        string ulp_u = findUPar(u);
        string ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else{
           parent[ulp_v] = ulp_u;
           rank[ulp_u]++; 
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts);

        for (int i = 0; i < accounts.size(); i++){
            for (int j = 1; j < accounts[i].size() -1; j++){
                if (ds.findUPar(accounts[i][j]) != ds.findUPar(accounts[i][j+1])) ds.unionR(accounts[i][j], accounts[i][j+1]);
            }
        }

        vector<vector<string>> res;
        unordered_map<string, string> name;
        for (auto it : ds.parent){
            if (ds.findUPar(it.first) == it.first){
                for (auto i : accounts){
                    for (string str : i){
                        if (str == it.first) name[it.first] = i[0];
                    }
                }
                
            }
        }

        unordered_map <string,int> idx;
        int i = 0;
        //cout << "hi";
        for (auto it : name){
            res.push_back({it.second});
            idx[it.first] = i;
            i++;
        }

        for (auto it : ds.parent){
            int i = idx[ds.findUPar(it.first)];
            res[i].push_back(it.first);
        }
        for (int i = 0; i < res.size(); i++){
            sort(res[i].begin() + 1, res[i].end());
        }
        return res;
    }
};