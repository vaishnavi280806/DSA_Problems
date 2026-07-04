class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int w = INT_MIN, x = INT_MIN, y = INT_MAX, z = INT_MAX;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > w){
                x = w;
                w = nums[i];
            }
            else if (nums[i] > x) x = nums[i];

            if (nums[i] < y){
                z = y;
                y = nums[i];
            }
            else if (nums[i] < z) z = nums[i];
        }

        return w*x - y*z;
    }
};