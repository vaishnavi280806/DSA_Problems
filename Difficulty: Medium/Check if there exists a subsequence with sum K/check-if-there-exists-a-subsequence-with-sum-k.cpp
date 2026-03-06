class Solution {
    bool helper(int idx, int n, vector<int>& arr, int k){
        if (k == 0) return true;
        if (k < 0 || idx == n) return false;
        
        if (helper(idx + 1, n, arr, k - arr[idx])) return true;
        if (helper(idx + 1, n, arr, k)) return true;
        return false;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return helper(0, n, arr, k);
    }
};