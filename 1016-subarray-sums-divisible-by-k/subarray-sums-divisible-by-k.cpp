class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map <int, int> hash;
        hash[0] = 1;
        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            if (hash.count(((prefix % k) + k) % k)) res += hash[((prefix % k) + k) % k];
            hash[((prefix % k) + k) % k]++;
        }
        return res;
    }
};