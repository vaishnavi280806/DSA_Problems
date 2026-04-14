class Solution {
    long long helper(int idx, int fact, vector<int>& robot, vector<vector<int>>& factory, vector<vector<long long>>& dp){
        if (idx == robot.size()) return 0;
        if (fact == factory.size()) return 1e18;
        if (dp[idx][fact] != -1e18) return dp[idx][fact];
        long long res = helper(idx, fact + 1, robot, factory, dp);

        long long cost = 0;
        long long limit = factory[fact][1];
        long long pos = factory[fact][0];

        for (int i = 0; i < limit && i + idx < robot.size(); i++){
            //factory[fact][1]--;
            cost += abs(robot[idx + i] - pos);
            res = min(res, cost + helper(idx + i + 1, fact + 1, robot, factory, dp));
            //factory[fact][1]++;
        }
        return dp[idx][fact] = res;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        int m = factory.size();
        vector<vector<long long>> dp (n, vector<long long> (m, -1e18));
        return helper(0, 0, robot, factory, dp);
    }
};