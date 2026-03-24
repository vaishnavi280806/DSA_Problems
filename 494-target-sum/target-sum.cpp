class Solution {
    int helper(int idx, int target, vector<int>& nums){
        if (idx == nums.size()){
            if (target == 0) return 1;
            return 0;
        }
        int pick = 0;
        if (nums[idx] <= target) pick = helper(idx + 1, target - nums[idx], nums);
        int notpick = helper(idx + 1, target, nums);

        return pick + notpick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0) + target;
        if (total % 2) return 0;
        int n = nums.size();
        return helper(0, total/2, nums);
    }
};