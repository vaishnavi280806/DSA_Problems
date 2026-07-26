class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        long long res = 0;
        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for (int i = 0; i < n; i++){
            int left = prefix[i];
            int rem = prefix[n-1] - left;

            int max_mid = (prefix[n-1] + left) / 2;
            int midstart = lower_bound(prefix.begin() + i + 1, prefix.end(), 2*left) - prefix.begin();
            int midend = upper_bound(prefix.begin() + i + 1, prefix.begin() + n  - 1, max_mid) - prefix.begin();
            midend--;

            int len = midend - midstart + 1;
            res += max(0, len);

        }
        return res % (long long)(1e9 + 7);
    }
};