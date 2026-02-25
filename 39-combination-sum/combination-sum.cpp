class Solution {
    void helper(int idx, vector<int>& candidates, int target, vector<int>& arr, int sum, vector<vector<int>>& res){
        if (sum > target || idx == candidates.size()) return;
        if (sum == target){
            res.push_back(arr);
            return;
        }
        arr.push_back(candidates[idx]);
        helper(idx, candidates, target, arr, sum + candidates[idx], res);
        arr.pop_back();
        helper(idx + 1, candidates, target, arr, sum, res);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        helper(0, candidates, target, arr, 0, res);
        return res;
    }
};