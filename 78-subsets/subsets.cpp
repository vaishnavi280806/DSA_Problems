class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets = 1 << nums.size();
        vector<vector<int>> res;
        for (int num = 0; num < subsets; num++){
            vector <int> sub;
            for (int i = 0; i < nums.size(); i++){
                if (num & (1 << i)) sub.push_back(nums[i]);
            }
            res.push_back(sub);
        }
        return res;
    }
};