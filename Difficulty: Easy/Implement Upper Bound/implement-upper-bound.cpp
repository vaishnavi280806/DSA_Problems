class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0, ans = arr.size(), high = ans - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (arr[mid] <= target){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
