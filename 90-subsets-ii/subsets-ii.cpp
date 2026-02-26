class Solution {
    void helper(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res){
        res.push_back(ds);
        for (int i = idx; i < nums.size(); i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            helper(i + 1, nums, ds, res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ds;
        helper(0, nums, ds, res);
        return res;
    }
};