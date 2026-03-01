class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long ans = 0;
        int l1 = 0, l2 = 0;
        unordered_map<int, int> hash1;
        unordered_map<int, int> hash2;
        int valid = 0;
        for (int r = 0; r < nums.size(); r++){
            hash1[nums[r]]++;
            while (hash1.size() > k){
                hash1[nums[l1]]--;
                if (hash1[nums[l1]] == 0) hash1.erase(nums[l1]);
                l1++;
            }
            hash2[nums[r]]++;
            if (hash2[nums[r]] == m) valid++;
            while (valid >= k){
                hash2[nums[l2]]--;
                if (hash2[nums[l2]] == m - 1) valid--;
                l2++;
            }
            if (l2 > l1) ans += l2 - l1;
        }
        return ans;
    }
};