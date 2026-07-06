class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        #define ll long long
        ll prefix = 0;
        unordered_map <ll, ll> hash;
        hash[0] = 1;
        ll res = 0;
        
        for (int x : nums){
            prefix ^= x;
            if (hash.count(prefix)) res += hash[prefix];
            hash[prefix]++;
        }
        return res;
    }
};