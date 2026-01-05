class Solution {
    int helper(vector<vector<int>> &mat, int mid){
        int sum = 0;
        for (int i = 0; i < mat.size(); i++){
            sum += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return sum;
    }
  public:
    int median(vector<vector<int>> &mat) {
        int low = 0, high = 2000;
        while (low <= high){
            int mid = (low + high)/2;
            int count = helper(mat, mid);
            if (count <= mat.size() * mat[0].size() / 2) low = mid + 1;
            else high = mid - 1;
        }
        return low;
        
    }
};
 