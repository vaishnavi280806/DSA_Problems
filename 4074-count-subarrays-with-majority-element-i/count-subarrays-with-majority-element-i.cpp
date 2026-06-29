class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] == target){
                cnt++;
                prefix[i] = cnt;
            }
            else prefix[i] = cnt;
        }
        int res  = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (i == 0 && prefix[j] > (j+1)/2) res++;
                else if (i != 0 && prefix[j] - prefix[i-1] > (j-i+1)/2) res++;
            }
        }
        return res;
    }
};