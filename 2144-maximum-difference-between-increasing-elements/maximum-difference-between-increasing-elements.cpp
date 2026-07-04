class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMin(n);
        prefixMin[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefixMin[i] = min(prefixMin[i-1], nums[i]);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++){
            res = max(res, nums[i] - prefixMin[i]);
        }
        if (res > 0) return res;
        return -1;
    }
};