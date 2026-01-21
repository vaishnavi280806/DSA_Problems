class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            sum = max(nums[i], nums[i] + sum);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};