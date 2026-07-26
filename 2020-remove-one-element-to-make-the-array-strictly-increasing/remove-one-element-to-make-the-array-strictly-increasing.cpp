class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int flag = 0;
        for (int i = 1; i < n; i++){
            if (flag > 1) return false;
            if (nums[i] <= nums[i-1]){
                flag++;
                if (i > 1 && nums[i-2] >= nums[i]) nums[i] =  nums[i-1];
            }
        }
        if (flag > 1) return false;
        return true;
    }
};