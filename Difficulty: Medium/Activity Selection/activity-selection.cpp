class Solution {
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> intervals;
        for(int i = 0; i < n; i++){
            intervals.push_back({start[i], finish[i]});
        }
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 1;
        int prevEnd = intervals[0].second;
        for (int i = 1; i < n; i++){
            if (intervals[i].first > prevEnd){
                ans++;
                prevEnd = intervals[i].second;
            }
        }
        return ans;
        
    }
};