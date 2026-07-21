class Solution {
    int helper(int idx, vector<pair<int, int>>& arr, vector<int>& dp){
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];

        int pick = 0;
        if ((idx - 1 >= 0) && (arr[idx].first - 1 == arr[idx - 1].first)) pick = arr[idx].first * arr[idx].second + helper(idx-2, arr, dp);
        else pick = arr[idx].first * arr[idx].second + helper(idx-1, arr, dp);
        int notpick = helper(idx-1, arr, dp);

        return dp[idx] = max(pick, notpick);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int, int>> arr;
        unordered_map <int, int> mp;

        for (int i = 0; i < nums.size(); i++){
           mp[nums[i]]++;
        }

        for (auto it : mp){
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end());
        vector<int> dp(arr.size(), -1);
        return helper(arr.size() -1, arr, dp);
    }
};