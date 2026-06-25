class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        vector<vector<int>> temp;
        
        for (int i = 0; i < n; i++){
            temp = dist;
            for (int j = 0; j < n; j++){
                for (int k = 0; k < n; k++){
                    if (dist[j][i] != 1e8 && dist[i][k] != 1e8 && dist[j][i] + dist[i][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }
};