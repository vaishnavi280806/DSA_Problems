class Solution {
    int helper(vector<int>& nums, int goal){
        if (goal == -1) return 0;
        int l = 0;
        int res = 0;
        int sum = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++){
            sum += nums[r];
            while (sum > goal){
                sum -= nums[l];
                l++;
            }
            res += r-l+1;
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};