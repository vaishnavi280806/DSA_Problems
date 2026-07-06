class Solution {
  public:
    int maxLength(vector<int>& arr) {
        unordered_map <int, vector<int>> hash;
        hash[0] = {-1};
        int prefix = 0;
        int res = 0;
        
        for (int i = 0; i < arr.size(); i++){
            prefix += arr[i];
            if (hash.count(prefix)) res = max(res, i - hash[prefix][0]);
            hash[prefix].push_back(i);
        }
        return res;
    }
};