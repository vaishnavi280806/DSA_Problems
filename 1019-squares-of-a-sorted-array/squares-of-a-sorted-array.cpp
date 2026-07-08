class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        vector<int> res(r+1);
        int idx = r;
        while (l <= r){
            if (nums[l] * nums[l] > nums[r] * nums[r]){
                res[idx] = nums[l] * nums[l];
                l++; idx--;

            }
            else{
                res[idx] = nums[r] * nums[r];
                r--; idx--;  
            }
        }
        return res;
    }
};