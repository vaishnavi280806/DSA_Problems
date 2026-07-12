class Solution {
    bool safe(int node, vector<unordered_set<int>>& graph, int m, int v, vector<int>& color, int col){
        for (int i = 0; i < v; i++){
            if (i != node && graph[i].count(node) && color[i] == col) return false;
        }  
        return true;
    }
    
    bool helper(int node, vector<unordered_set<int>>& graph, int m, int v, vector<int>& color){
        if (node == v) return true;
        
        for (int i = 1; i <= m; i++){
            if (safe(node, graph, m, v, color, i)){
                color[node] = i;
                if (helper(node+1, graph, m, v, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<unordered_set<int>> graph(v);
        
        for (auto it : edges){
            graph[it[0]].insert(it[1]);
        }
        vector<int> color(v, 0);
        return helper(0, graph, m, v, color);
        
    }
};