class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> hash;
        int psum = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){
            psum += arr[i];
            if (psum == k) ans = max(ans, i+1);
            if (hash.count(psum - k)) ans = max(ans, i - hash[psum - k]);
            if (!hash.count(psum)) hash[psum] = i;
        }
        return ans;
        
    }
};