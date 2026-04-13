class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp (n, 1);
        vector<int> hash(n);
        int maxi = 0;
        for (int i = 0; i < n; i++){
            hash[i] = i;
            for (int j = 0; j < i; j++){
                if (nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            if (dp[i] > dp[maxi]) maxi = i;
        }
        vector<int> res;
        int prev = maxi;
        while (hash[prev] != prev){
            res.push_back(nums[prev]);
            prev = hash[prev];
        }
        res.push_back(nums[prev]);
        return res;
    }
};