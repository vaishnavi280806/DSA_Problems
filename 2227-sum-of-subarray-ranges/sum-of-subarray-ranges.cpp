class Solution {
    vector<int> NSE(vector<int> nums){
        vector<int> nse(nums.size());
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && nums[stk.top()] >= nums[i]) stk.pop();
            if (stk.empty()) nse[i] = nums.size();
            else nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }
    vector<int> NGE(vector<int> nums){
        vector<int> nge(nums.size());
        stack<int> stk;
        for (int i = nums.size() - 1; i >= 0; i--){
            while (!stk.empty() && nums[stk.top()] <= nums[i]) stk.pop();
            if (stk.empty()) nge[i] = nums.size();
            else nge[i] = stk.top();
            stk.push(i);
        }
        return nge;
    }

    vector<int> PSEE(vector<int> nums){
        vector<int> psee(nums.size());
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++){
            while (!stk.empty() && nums[stk.top()] > nums[i]) stk.pop();
            if (stk.empty()) psee[i] = -1;
            else psee[i] = stk.top();
            stk.push(i);
        }
        return psee;
    }

    vector<int> PGEE(vector<int> nums){
        vector<int> pgee(nums.size());
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++){
            while (!stk.empty() && nums[stk.top()] < nums[i]) stk.pop();
            if (stk.empty()) pgee[i] = -1;
            else pgee[i] = stk.top();
            stk.push(i);
        }
        return pgee;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse = NSE(nums);
        vector<int> psee = PSEE(nums);
        vector<int> nge = NGE(nums);
        vector<int> pgee = PGEE(nums);
        long long mini = 0, maxi = 0;
        for (int i = 0; i < nums.size(); i++){
            mini += (long long)(nse[i] - i) * (long long)(i - psee[i]) * (long long)nums[i];
            maxi += (long long)(nge[i] - i) * (long long)(i - pgee[i]) * (long long)nums[i];
        }
        return maxi - mini;
    }
};