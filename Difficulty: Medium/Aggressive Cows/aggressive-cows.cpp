class Solution {
    int helper(vector<int> &stalls, int mid, int k){
        int cnt = 1, last = stalls[0];
        for (int i = 0; i < stalls.size(); i++){
            if (stalls[i] - last >= mid){
                last = stalls[i];
                cnt++;
            }
            if (cnt >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        while (low <= high){
            int mid = low + (high - low)/2;
            if (helper(stalls, mid, k)) low = mid + 1;
            else high = mid - 1;
            
        }
        return high;
    }
};