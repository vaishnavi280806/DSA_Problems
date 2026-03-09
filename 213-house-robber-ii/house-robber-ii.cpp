class Solution {
      int helper(vector<int>& nums, int start, int end) {
        int prev = nums[start];
        int prev2 = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++){
            int way1 = nums[i] + prev;
            int way2 = prev2;
            prev = prev2;
            prev2 = max(way1, way2);
        }
        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() - 1));
    }
};