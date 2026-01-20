class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        /*101101111
        101100111*/
        for (int i = 0; i < nums.size(); i++){
            int ans = -1;
            int d = 1;
            while ((nums[i] & d) != 0){
                ans = nums[i] & (~d);
                d = d << 1;
            }
            nums[i] = ans;
        }
        return nums;
    }
};