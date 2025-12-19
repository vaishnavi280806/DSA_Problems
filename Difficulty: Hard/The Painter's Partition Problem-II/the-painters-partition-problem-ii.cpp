class Solution {
    int helper(vector<int>& nums, int mid){
        int cnt = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (sum + nums[i] <= mid) sum += nums[i];
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
public:
    int minTime(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            int num = helper(nums, mid);
            if (num <= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};