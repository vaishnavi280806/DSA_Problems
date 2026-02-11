class Solution {
    static bool compare(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int cnt = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (prevEnd > intervals[i][0]) cnt++;
            else prevEnd = intervals[i][1];
        }
        return cnt;
    }
};