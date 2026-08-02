class Solution {
    static bool compare(vector<int> &a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare);
        int n = points.size();
        int last = points[0][1];
        int cnt = 1;
        for (int i = 1; i < n; i++){
            if (points[i][0] <= last) continue;
            else {
                cnt++;
                last = points[i][1];
            }
        }
        return cnt;
    }
};