class Solution {
    int helper(int idx, int target, vector<int>& nums){
        if (idx == nums.size()){
            if (target == 0) return 1;
            return 0;
        }
        int plus = helper(idx + 1, target - nums[idx], nums);
        int minus = helper(idx + 1, target + nums[idx], nums);

        return plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, target, nums);
    }
};