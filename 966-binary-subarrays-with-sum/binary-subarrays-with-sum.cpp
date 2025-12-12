class Solution {
private:
    int helper(vector<int>& nums, int goal){
        if (goal == -1) return 0;
        int l = 0, count = 0, sum = 0;

        for (int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while (sum > goal){
                sum -= nums[l];
                l++;
            }
            if (sum <= goal){
                count += r - l + 1;
            }
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};