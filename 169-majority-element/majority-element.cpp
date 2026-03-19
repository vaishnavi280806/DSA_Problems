class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == num) cnt++;
            else cnt--;
            if (cnt == 0 && i+1 < nums.size()) num = nums[i+1];
        }
        return num;
    }
};