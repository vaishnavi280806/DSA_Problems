class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat.size();
        while (low <= high){
            int mid = low + (high - low)/2;
            int max_index = 0;
            for (int i = 0; i < mat[0].size(); i++){
                if (mat[mid][i] > mat[mid][max_index]) max_index = i;
            }
            int top = mid - 1 >= 0 ? mat[mid - 1][max_index] : -1;
            int bottom = mid + 1 < mat.size() ? mat[mid + 1][max_index] : -1;

            if (mat[mid][max_index] > top && mat[mid][max_index] > bottom) return {mid, max_index};
            else if (mat[mid][max_index] < top) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};