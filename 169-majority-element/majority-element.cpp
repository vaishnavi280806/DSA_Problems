class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }
        for (auto it : hash){
            if (it.second > nums.size()/2) return it.first;
        }
        return -1;
    }
};