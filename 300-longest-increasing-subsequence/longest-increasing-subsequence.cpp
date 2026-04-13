class Solution {
    /*int helper(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if (idx == nums.size()) return 0;
        if (dp[idx][prev+1] != -1e5) return dp[idx][prev+1];
        int len = helper(idx+1, prev, nums, dp);
        if (prev == -1 || nums[idx] > nums[prev]){
            len = max(len, 1 + helper(idx+1, idx, nums, dp));
        }
        return dp[idx][prev+1] = len;
    }*/
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n, vector<int> (n+1, -1e5));
        //return helper(0, -1, nums, dp);

        /*vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
        
        for (int idx = n-1; idx >= 0; idx--){
            for (int prev = idx-1; prev >= -1; prev--){
                int len = dp[idx+1][prev+1];
                if (prev == -1 || nums[idx] > nums[prev]){
                    len = max(len, 1+ dp[idx+1][idx+1]);
                }
                dp[idx][prev+1] = len;
            }
        }
        return dp[0][0];*/

        /*vector<int> prevA(n+1, 0);

        for (int idx = n-1; idx >= 0; idx--){
            vector<int> temp(n+1, 0);
            for (int prev = idx-1; prev >= -1; prev--){
                int len = prevA[prev+1];
                if (prev == -1 || nums[idx] > nums[prev]){
                    len = max(len, 1+ prevA[idx+1]);
                }
                temp[prev+1] = len;
            }
            prevA = temp;
        }
        return prevA[0];*/

        /*vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;*/

        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++){
            if (nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};