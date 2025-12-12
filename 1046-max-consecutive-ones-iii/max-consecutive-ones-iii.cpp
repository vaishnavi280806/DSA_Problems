class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, count = 0, maxNum = 0;
        for (int r = 0; r < nums.size(); r++){
            if (nums[r] == 0){
                count++;
            }
            while (count > k){
                if (nums[l] == 0){
                    count--;
                }
                l++;
            }
            maxNum = max(maxNum, r - l + 1);
            
        }
        return maxNum;
    }
};