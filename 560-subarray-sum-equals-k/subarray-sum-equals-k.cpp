class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map <int,  int> hash;
        hash[0] = 1;

        int res = 0;
        for (int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            if (hash.count(prefix - k)) res += hash[prefix - k];
            hash[prefix]++;
        }
        return res;
    }
};