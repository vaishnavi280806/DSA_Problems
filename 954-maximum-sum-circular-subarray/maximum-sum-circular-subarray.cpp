class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int total = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];
        for (int i = 1; i < n; i++){
            total += nums[i];
            maxsum = max(maxsum + nums[i], nums[i]);
            maxi = max(maxi, maxsum);
            minsum = min(minsum + nums[i], nums[i]);
            mini = min(mini, minsum);
        }
        if (maxi < 0) return maxi;
        return max(maxi, total - mini);
    }
};