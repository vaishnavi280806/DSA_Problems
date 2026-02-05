// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
        unordered_map<int, int> hash;
        vector<int> res = arr;
        sort(res.begin(), res.end());
        int i = 1;
        for (auto x : res){
            if (hash[x] == 0) hash[x] = i++;
        }
        for (auto &x : arr){
            x = hash[x];
        }
        return arr;
        
    }
};
