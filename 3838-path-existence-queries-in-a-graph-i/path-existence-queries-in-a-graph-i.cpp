class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        vector<int> parent(n);

        for (int i = 1; i < n; i++){
            if (nums[i] - nums[i-1] <= maxDiff) parent[i] = parent[i-1];
            else parent[i] = i;
        }

        vector<bool> res(q.size());
        for (int i = 0; i < q.size(); i++){
            if (parent[q[i][0]] == parent[q[i][1]]) res[i] = true;
            else res[i] = false;
        }

        return res;
    }
};