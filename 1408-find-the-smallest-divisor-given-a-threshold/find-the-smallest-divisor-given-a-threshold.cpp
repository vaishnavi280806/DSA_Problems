class Solution {
    int helper(vector<int>& nums, int mid){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += ceil((float)nums[i]/mid);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high){
            int mid = low + (high - low)/2;
            int sum = helper(nums, mid);
            if (sum <= threshold) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};