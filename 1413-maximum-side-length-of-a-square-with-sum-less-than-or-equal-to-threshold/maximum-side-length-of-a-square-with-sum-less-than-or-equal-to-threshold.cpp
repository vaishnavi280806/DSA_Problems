class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> p(m+1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; i++){
            for (int j = 1; j < n + 1; j++){
                p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int low = 0, high = min(m, n);
        while (low <= high){
            int mid = low + (high - low)/2;
            int flag = 0;
            for (int i = 1; i <=m - mid + 1; i++){
                for (int j = 1; j <= n - mid + 1; j++){
                    int r = i + mid - 1, c = j + mid - 1;
                    int sum = p[r][c] - p[i-1][c] - p[r][j-1] + p[i-1][j-1];

                    if (sum <= threshold){
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};