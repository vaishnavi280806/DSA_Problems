class Solution {
    int helper(int mid, int n){
        int ans = 1;
        for (int i = 0; i < n; i++){
            ans *= mid;
        }
        return ans;
    }
  public:
    int nthRoot(int n, int m) {
        if (m == 0 || m == 1 || n == 1) return m;
        int low = 0, high = m/2;
        while (low <= high){
            int mid = low + (high - low)/2;
            int ans = helper(mid, n);
            if (ans == m) return mid;
            else if (ans > m) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
        
    }
};