class Solution {
    void helper(vector<int>& nums, vector<int>& ds, unordered_set<int>& hash, vector<vector<int>>& res){
        if (ds.size() == nums.size()){
            res.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            if (hash.count(nums[i])) continue;
            hash.insert(nums[i]);
            ds.push_back(nums[i]);
            helper(nums, ds, hash, res);
            ds.pop_back();
            hash.erase(nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        unordered_set<int> hash;
        vector<vector<int>> res;
        helper(nums, ds, hash, res);
        return res;
    }
};