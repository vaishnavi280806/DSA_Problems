class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < n; i++){
            hash[nums[i]].push_back(i);
        }
        for (auto &it : hash){
            auto &arr = it.second;

            int m = arr.size();
            long long right = accumulate(arr.begin(), arr.end(), 0LL);
            long long left = 0;

            for (int i = 0; i < m; i++){
                res[arr[i]] = (i * (long long)arr[i]) - left + right - ((m - i) * (long long)arr[i]);
                left += arr[i];
                right -= arr[i];
            }
        }
        return res;
    }
};