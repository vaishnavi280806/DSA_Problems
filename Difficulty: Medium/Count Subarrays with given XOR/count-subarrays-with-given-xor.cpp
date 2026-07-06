class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int prefix = 0;
        unordered_map <int, int> hash;
        hash[0] = 1;
        int res = 0;
        
        for (int x : arr){
            prefix ^= x;
            if (hash.count(prefix^k)) res += hash[prefix^k];
            hash[prefix]++;
        }
        return res;
        
    }
};