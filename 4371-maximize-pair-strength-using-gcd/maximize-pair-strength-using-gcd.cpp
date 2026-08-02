class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        #define ll long long
        int n = nums.size();
        ll res = LLONG_MIN;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                res = max(res, (ll)nums[i] * (ll)nums[j] / (ll)pow(gcd(nums[i], nums[j]), 2));
            }
        }
        return res;
    }
};