class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;  
        int furthest  = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (i > furthest) return false;
            furthest = max(furthest, i + nums[i]);
            if (furthest >= nums.size() - 1) return true;
        }
        return false;
    }
};