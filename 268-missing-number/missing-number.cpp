class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] != i) return i;
        }
        return nums.size();*/

        /*vector<int> arr(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++){
            arr[nums[i]] = 1;
        }
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] == 0) return i;
        }
        return -1;*/
        int actual = accumulate(nums.begin(), nums.end(), 0);
        int req = nums.size();
        req = req * (req+1)/2;
        return req - actual;

    }
};