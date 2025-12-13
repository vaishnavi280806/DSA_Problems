class Solution {
private:
    int helper(vector<int>& nums, int k){
        unordered_map <int,int> hash;
        int l = 0, c = 0;
        for (int r = 0; r < nums.size(); r++){
            hash[nums[r]]++;
            while(hash.size() > k){
                hash[nums[l]]--;
                if (hash[nums[l]] == 0){
                    hash.erase(nums[l]);
                }
                l++;
            }
            c += r - l + 1;
        }
        return c;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};