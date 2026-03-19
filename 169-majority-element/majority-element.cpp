class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; r++){
            if (nums[r] == nums[l]) continue;
            if (r-l > n/2) return nums[l];
            else l = r;
        }
        return nums[l];
    }
};