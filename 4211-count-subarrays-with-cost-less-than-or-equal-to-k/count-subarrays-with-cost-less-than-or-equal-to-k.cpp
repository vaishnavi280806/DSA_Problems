class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long c = 0;
        deque<int> maxi, mini;
        maxi.push_back(0);
        mini.push_back(0);
        int l = 0;
        for (int r = 0; r < nums.size(); r++){
            while (!maxi.empty() && nums[maxi.back()] <= nums[r]) maxi.pop_back();
            maxi.push_back(r);
            while (!mini.empty() && nums[mini.back()] >= nums[r]) mini.pop_back();
            mini.push_back(r);
            while (((long long)nums[maxi.front()] - (long long)nums[mini.front()]) * (r-l+1) > k){
                if (!maxi.empty() && maxi.front() <= l) maxi.pop_front();
                if (!mini.empty() && mini.front() <= l) mini.pop_front();
                l++;
            }
            c += r - l + 1;
        }
        return c;
    }
};