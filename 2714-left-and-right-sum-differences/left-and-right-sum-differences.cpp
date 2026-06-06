class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum = accumulate(nums.begin(), nums.end(), 0);
        int prefix = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            res.push_back(abs(prefix - (rsum - nums[i])));
            prefix += nums[i];
            rsum -= nums[i];
        }
        return res;
    }
};