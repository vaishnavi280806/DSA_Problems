class Solution {
private:
    void reverse(vector<int> &nums, int l, int r){
         while (l < r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;

            l++; r--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k%nums.size() - 1);
        reverse(nums, k%nums.size(), nums.size() - 1);       
    }
};