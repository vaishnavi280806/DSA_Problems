class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowS = 0, rowE = matrix.size() -1, colS = 0, colE = matrix[0].size() -1;

        while (rowS <= rowE && colS <= colE){
            for (int i = colS; i <= colE; i++) res.push_back(matrix[rowS][i]);
            rowS++;
            if (rowS > rowE) break;


            for (int i = rowS; i <= rowE; i++) res.push_back(matrix[i][colE]);
            colE--;
            if (colS > colE) break;

            for (int i = colE; i >= colS; i--) res.push_back(matrix[rowE][i]);
            rowE--;
            if (rowS > rowE) break;

            for (int i = rowE; i >= rowS; i--) res.push_back(matrix[i][colS]);
            colS++;
            if (colS > colE) break;
        }
        return res;
    }
};