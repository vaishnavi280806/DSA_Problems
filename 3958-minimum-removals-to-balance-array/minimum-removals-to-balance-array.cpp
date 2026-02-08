class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int ans = 0;
        for (int r = 0; r < nums.size(); r++){
            if ((long long)nums[r] > k * (long long)nums[l]) l++;
            ans = max(ans, r - l + 1);
        }
        return nums.size() - ans;
    }
};