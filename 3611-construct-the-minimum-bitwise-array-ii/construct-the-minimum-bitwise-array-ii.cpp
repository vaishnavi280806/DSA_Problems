class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (auto &x: nums){
            int ans = -1, d = 1;
            while ((x & d) != 0){
                ans = x & (~d);
                d = d << 1;
            }
            x = ans;
        }
        return nums;
    }
};