class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int cur = 1;
        int left = 0, right = n-1;
        int top = 0, bottom = n-1;

        while (cur <= n*n){
            for (int i = left; i <= right; i++) mat[top][i] = cur++;
            top++;

            if (cur > n*n) break;

            for (int i = top; i <= bottom; i++) mat[i][right] = cur++;
            right--;

            if (cur > n*n) break;

            for (int i = right; i >= left; i--) mat[bottom][i] = cur++;
            bottom--;

            if (cur > n*n) break;

            for (int i = bottom; i >= top; i--) mat[i][left] = cur++;
            left++;
        }
        return mat;
    }
};