class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int maxi = 0;
        for (int idx = 0; idx < n; idx++){
            hash[idx] = idx;
            for (int prev = 0; prev < idx; prev++){
                if (arr[idx] > arr[prev]){
                    if (dp[prev] + 1 > dp[idx]){
                        dp[idx] = dp[prev] + 1;
                        hash[idx] = prev;
                    }
                }
            }
            if (dp[idx] > dp[maxi]) maxi = idx;
        }
        vector<int> res;
        int prev = maxi;
        while (prev != hash[prev]){
            res.push_back(arr[prev]);
            prev = hash[prev];
        }
        res.push_back(arr[prev]);
        reverse(res.begin(), res.end());
        return res;
        
    }
};