class Solution {
    void helper(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res){
        if (idx > nums.size()) return;
        if (idx == nums.size()){
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx + 1, nums, ds, res);
        ds.pop_back();
        helper(idx + 1, nums, ds, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, nums, ds, res);
        return res;
    }
};