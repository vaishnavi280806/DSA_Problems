class Solution {
    int helper(int start, int end, vector<int>& nums, vector<vector<int>>& dp){
        if (start == end) return nums[start];
        if (dp[start][end] != -1) return dp[start][end];
        int first = nums[start] - helper(start+1, end, nums, dp);
        int last = nums[end] - helper(start, end - 1, nums, dp);

        return dp[start][end] = max(first, last);

        
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int res = helper(0, n - 1, nums, dp);
        return (res >= 0);
    }
};