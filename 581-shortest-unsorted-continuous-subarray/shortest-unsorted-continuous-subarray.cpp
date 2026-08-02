class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int r = -1;
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++){
            maxi = max(nums[i], maxi);
            if (nums[i] < maxi){
                r = i;
            }
        }
        int l = -1;
        int mini = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--){
            mini = min(nums[i], mini);
            if (nums[i] >  mini){
                l = i;
            }
        }
        if (l == -1 || r == -1) return 0;
        return r-l+1;
    }
};