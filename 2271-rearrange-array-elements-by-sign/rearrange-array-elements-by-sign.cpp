class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //3 1 9 4 -1 -5 -2 2 -4 -6
        //3 -1 1 -5 9 -2 4 -4 2 -6

        //-2 3 -5 1 -4 2
        //3 -2 1 -5 2 -4
        vector<int> pos, neg;

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++){
            if (i % 2 == 0) nums[i] = pos[i/2];
            else nums[i] = neg[i/2];
        }
        return nums;
    }
};