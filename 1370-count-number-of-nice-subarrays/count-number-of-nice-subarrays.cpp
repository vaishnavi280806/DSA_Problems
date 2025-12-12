class Solution {
private:
        int helper(vector<int>& nums, int k){
            int l = 0, count = 0, kcount = 0;
            for (int r = 0; r < nums.size(); r++){
                if (nums[r]%2 == 1){
                    kcount++;
                }
                while (kcount > k){
                    if (nums[l]%2 == 1){
                        kcount--;
                    }
                    l++;
                }
                count += r - l + 1;
            }
            return count;
        }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};