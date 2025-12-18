class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (nums[1] < nums[0]) return 0;
        if (nums[n - 2] < nums[n - 1]) return n-1;
        int low = 1, high = nums.size() - 2;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            if (nums[mid] < nums[mid + 1]) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};