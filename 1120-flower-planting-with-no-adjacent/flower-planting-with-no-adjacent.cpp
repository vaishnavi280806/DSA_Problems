class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);

        for (auto it : paths){
            graph[it[0] - 1].push_back(it[1] - 1);
            graph[it[1] - 1].push_back(it[0] - 1);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++){
            vector<bool> used(5);
            for (int it : graph[i]) used[res[it]] = true;
            for (int j = 1; j <= 4; j++){
                if (!used[j]){
                    res[i] = j;
                }
            }
        }
        return res;
    }
};