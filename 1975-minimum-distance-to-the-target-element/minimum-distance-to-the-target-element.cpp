class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int res = INT_MAX;
        while (i < nums.size()){
            if (nums[i] == target){
                res = i - start;
                break;
            }
            i++;
        }
        i = start - 1;
        while (i >= 0){
            if (nums[i] == target){
                res = min(res, start - i);
                break;
            }
            i--;
        }
        return res;
    }
};