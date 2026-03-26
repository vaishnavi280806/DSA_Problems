class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int x = 1e5 + 1;
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return true;
        vector<int> bottom (x), top(x);

        long long total = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                total += grid[i][j];
                bottom[grid[i][j]]++;
            }
        }

        long long topSum = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                topSum += grid[i][j];
                bottom[grid[i][j]]--;
                top[grid[i][j]]++;
            }
            long long bottomSum = total - topSum;
            if (topSum == bottomSum) return true;

            long long diff = abs(topSum - bottomSum);

            if (diff < x){
                if (topSum > bottomSum){
                    if (i == 0 && n!= 1){
                        if (grid[0][0] == diff || grid[0][n-1] == diff) return true;
                    }
                    else{
                        if (n == 1){
                                if (grid[i][0] == diff || grid[0][0] == diff) return true;
                            }
                        else if (top[diff] > 0) return true;
                    }
                }
                else{
                    if (bottomSum > topSum){
                        if (i == m-2 && n != 1){
                            if (grid[m-1][0] == diff || grid[m-1][n-1] == diff) return true;
                        }
                        else{
                            if (n == 1){
                                if (grid[i+1][0] == diff || grid[m-1][0] == diff) return true;
                            }
                            else if (bottom[diff] > 0) return true;
                        }
                    }
                }
            }

        }

        vector<int> left (x), right(x);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                right[grid[j][i]]++;
            }
        }
        

        long long leftSum = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                leftSum += grid[j][i];
                right[grid[j][i]]--;
                left[grid[j][i]]++;
            }
            long long rightSum = total - leftSum;
            if (leftSum == rightSum) return true;
            cout << leftSum << " " << rightSum << endl;
            long long diff = abs(leftSum - rightSum);

            if (diff < x){
                if (leftSum > rightSum){
                    if (i == 0 && m != 1){
                        if (grid[0][0] == diff || grid[m-1][0] == diff) return true;
                    }
                    else{
                        if (m == 1){
                                if (grid[0][i] == diff || grid[0][0] == diff) return true;
                            }
                        else if (left[diff] > 0) return true;
                    }
                }
                else{
                    if (rightSum > leftSum){
                        if (i == n-2 && m != 1){
                            if (grid[0][n-1] == diff || grid[m-1][n-1] == diff) return true;
                        }
                        else{
                            if (m == 1){
                                if (grid[0][i+1] == diff || grid[0][n-1] == diff) return true;
                            }
                            else if (right[diff] > 0) return true;
                        }
                    }
                }
            }

        }
        return false;

    }
};