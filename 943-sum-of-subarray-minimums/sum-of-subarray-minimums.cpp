class Solution {
    vector<int> NSE(vector<int>& arr){
        stack<int> stk;
        vector<int> nse(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--){
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            if (stk.empty()) nse[i] = arr.size();
            else nse[i] = stk.top();
            stk.push(i);
        }
        return nse;
    }
    vector<int> PSEE(vector<int>& arr){
        stack<int> stk;
        vector<int> psee(arr.size());
        for (int i = 0; i < arr.size(); i++){
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            if (stk.empty()) psee[i] = -1;
            else psee[i] = stk.top();
            stk.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = NSE(arr);
        vector<int> psee = PSEE(arr);
        int mod = 1e9 + 7;
        long long res = 0;
        for (int i = 0; i < arr.size(); i++){
            res = (res + ((((long  long)(nse[i] - i) * (long long)(i - psee[i])) % mod) * arr[i]) % mod) % mod;
        }
        return (int)res;
    }
};