class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int cur = 1;
        int top = rStart;
        int bottom = rStart;
        int left = cStart;
        int right = cStart;

        res.push_back({rStart, cStart});

        while (cur < rows * cols){
            right++;
            for(int i = left+1; i <= right; i++){
                if (0 <= top && top < rows && 0 <= i && i < cols){
                    res.push_back({top, i});
                    cur++;
                    if (cur == rows* cols) return res;
                }
            }

            bottom += 1;
            for (int i = top+1; i <= bottom; i++){
                if (0 <= right && right < cols && 0 <= i && i < rows){
                    res.push_back({i, right});
                    cur++;
                    if (cur == rows* cols) return res;
                }
            }

            left--;
            for (int i = right-1; i >= left; i--){
                if (0 <= bottom && bottom < rows && 0 <= i && i < cols){
                    res.push_back({bottom, i});
                    cur++;
                    if (cur == rows* cols) return res;
                }
            }

            top--;
            for (int i = bottom-1; i >= top; i--){
                if (0 <= left && left < cols && 0 <= i && i < rows){
                    res.push_back({i, left});
                    cur++;
                    if (cur == rows* cols) return res;
                }
            }
        }
        return res;

    }
};