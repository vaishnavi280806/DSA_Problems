class Solution {
    int helper(int idx, int mask, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if (idx == nums1.size()) return 0;
        if (dp[idx][mask] != -1) return dp[idx][mask];

        int mini = INT_MAX;
        for (int i = 0; i < nums1.size(); i++){
            if ((mask & (1 << i)) == 0){
                mini = min(mini, (nums1[idx] ^ nums2[i]) + helper(idx+1, (mask | (1 << i)), nums1, nums2, dp));
            }
        }
        return dp[idx][mask] = mini;
    }
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int> ((1 << nums1.size()), -1));
        return helper(0, 0, nums1, nums2, dp);
    }
};