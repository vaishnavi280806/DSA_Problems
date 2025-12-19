class Solution {
    int helper(vector<int> &arr, int mid, int k){
        int cnt = 1, sum = 0;
        for (int i = 0; i < arr.size(); i++){
            if (sum + arr[i] <= mid) sum += arr[i];
            else{
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) return - 1;
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            int cnt = helper(arr, mid, k);
            if (cnt <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};