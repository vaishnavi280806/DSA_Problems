class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int l = 0;
        int kcount = 0;
        long long ans = 0;
        unordered_map <int, int> hash;
        for (int r = 0; r < nums.size(); r++){
            kcount += hash[nums[r]];
            hash[nums[r]]++;
            while(kcount >= k){
                ans += nums.size() - r;
                hash[nums[l]]--;
                kcount -= hash[nums[l]];
                if (hash[nums[l]] == 0) hash.erase(nums[l]);
                l++;
                
            }
        }
        return ans;
    }
};