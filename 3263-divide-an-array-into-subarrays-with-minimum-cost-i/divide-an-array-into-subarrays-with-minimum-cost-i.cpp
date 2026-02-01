class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        sort(nums.begin() + 1, nums.end());
        sum += accumulate(nums.begin() + 1, nums.begin() + 3, 0);
        return sum;
    }
};