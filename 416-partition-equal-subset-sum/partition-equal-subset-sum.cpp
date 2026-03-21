class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 == 1) return false;
        sum = sum/2;
        int n = arr.size();
        vector<bool> prev(sum+1), temp(sum+1);
        prev[0] = temp[0] = true;
        //prev[arr[0]] = true;
        
        for (int i = 1; i < n; i++){
            for (int j = 1; j <= sum; j++){
                bool nottake = prev[j];
                bool take = false;
                if (arr[i] <= j) take = prev[j - arr[i]];
                temp[j] = nottake || take;
            }
            prev = temp;
        }
        return prev[sum];
    }
};