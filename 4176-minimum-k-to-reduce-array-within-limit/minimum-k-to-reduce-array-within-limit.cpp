class Solution {
    int helper(vector<int> nums, int mid){
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            count += ceil((floor)(nums[i])/mid);
        }
        return count;
    }
public:
    int minimumK(vector<int>& nums) {
        int low = 1;
        int high = 1e5;

        while (low <= high){
            int mid = low + (high - low)/2;
            int op = helper(nums, mid);
            if (op <= pow(mid, 2)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};