class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pSum(nums.size());
        pSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++){
            pSum[i] = pSum[i-1] + nums[i];
        }
        unordered_map <int,int> hash;
        int count = 0;

        for (int r = 0; r < nums.size(); r++){
            if (pSum[r] == k) count++;
            if (hash.count(pSum[r] - k)){
                count += hash[pSum[r] - k];
            }
            hash[pSum[r]]++;
        }
        return count;
    }
};