class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != target[i]) hash.insert(nums[i]);
        }
        return hash.size();
    }
};