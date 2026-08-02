class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();
        vector<long long> prefix(n, 0);
        prefix[0] = tasks[0];

        for (int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + tasks[i];
        }

        // 1 5 9
        vector<int> res;
        long long sum = 0;
        for (int i = 0; i < m; i++){
            sum += shifts[i];
            int ub = upper_bound(prefix.begin(), prefix.end(), sum) - prefix.begin();
            res.push_back(n - ub);
            if (ub == n) sum = 0;
        }
        return res;
    }
};