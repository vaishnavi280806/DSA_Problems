// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(), m = arr[0].size(), count = 0, ans = -1;
        for (int i = 0; i < n; i++){
            if (arr[i][0] == 1) return i;
            int low = 1, high = m - 1;
            while (low <= high){
                int mid = low + (high - low)/2;
                if (arr[i][mid - 1] == 0 && arr[i][mid] == 1){
                        if (m - mid > count){
                            count = m - mid;
                            ans = i;
                        }
                        break;
                }
                else if (arr[i][mid] == 0) low = mid + 1;
                else high = mid - 1;
                
            }
        }
        return ans;
        
    }
};