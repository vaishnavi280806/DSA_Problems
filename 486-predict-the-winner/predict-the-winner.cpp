class Solution {
    int helper(int start, int end, vector<int>& nums){
        if (start == end) return nums[start];

        int first = nums[start] - helper(start+1, end, nums);
        int last = nums[end] - helper(start, end - 1, nums);

        return max(first, last);

        
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int res = helper(0, nums.size() - 1, nums);
        return (res >= 0);
    }
};