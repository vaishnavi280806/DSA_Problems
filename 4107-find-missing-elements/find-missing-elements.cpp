class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;

        int start = nums[0];
        for (int it : nums){
            while (start != it){
                res.push_back(start);
                start++;
            }
            start++;
        }
        return res;
    }
};