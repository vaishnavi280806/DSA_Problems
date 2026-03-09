class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prev = nums[0];
        int prev2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            int way1 = nums[i] + prev;
            int way2 = prev2;
            prev = prev2;
            prev2 = max(way1, way2);
        }
        return prev2;
    }
};