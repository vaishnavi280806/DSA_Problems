class Solution {
    void helper(int idx, vector<int>& candidates, int target, vector<int>& ds, int sum, vector<vector<int>>& res){
        if (sum == target){
            res.push_back(ds);
            return;
        }
        if (idx >= candidates.size() || sum > target) return;
        
        for (int i = idx; i < candidates.size(); i++){
            if (i > idx && candidates[i] == candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            helper(i+1, candidates, target, ds, sum + candidates[i], res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> res;
        helper(0, candidates, target, ds, 0, res);

        return res;
    }
};