class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        for (int mid = 0; mid <= high; mid++){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
            }
            else if (nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
                mid--;
            }
        }
    }
};