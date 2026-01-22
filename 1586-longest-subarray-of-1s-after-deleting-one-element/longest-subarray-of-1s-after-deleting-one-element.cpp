class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int ans = 0;
        int zero = 0;
        for (int r = 0; r < nums.size(); r++){
            if (nums[r] == 0){
                zero++;
            }
            while (zero > 1){
                if (nums[l] == 0) zero--;
                l++;
            }
            ans = max(ans, r - l + 1 - zero);
            
        }
        if (zero == 1) return ans;
        else return ans-1;
    }
};