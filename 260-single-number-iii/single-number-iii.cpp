class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long Xor = 0;
        for (int i = 0; i < nums.size(); i++) Xor = Xor ^ nums[i];
        long long setbit = Xor & (Xor - 1) ^ Xor;
        long long set1 = 0, set2 = 0;
        for (auto x : nums){
            if (x & setbit) set1 = set1 ^ x;
            else set2 = set2 ^ x;
        }
        return {(int)set1, (int)set2};
    }
};