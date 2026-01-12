class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int count = 0;
        for (int i = 0; i < points.size() - 1; i++){
            int curX = points[i][0];
            int curY = points[i][1];
            int nextX = points[i + 1][0];
            int nextY = points[i + 1][1];
            count += max(abs(nextX - curX), abs(nextY - curY));
        }
        return count;
    }
};