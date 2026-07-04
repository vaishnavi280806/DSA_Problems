class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1 2 4 9 6 5 3 -> 1 2 5 3 4 6 9
        //1 2 5 4 3 -> 1 3 2 4 5
        int n = nums.size();

        //step 1: 1 2 5 4 3 -> find the idx where it decreases
        int  idx = -1;
        for (int i = n-2; i >= 0; i--){
            if (nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        // it is in descending order
        if (idx == -1) return reverse(nums.begin(), nums.end());

        //step 2: 1 3 5 4 2 -> swap a smallest number > than nums[idx] at idx
        for (int i = n-1; i >= idx; i--){
            if (nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        //step 3: 1 3 2 4 5 -> simply reverse after idx
        reverse(nums.begin() + idx + 1, nums.end());



    }
};