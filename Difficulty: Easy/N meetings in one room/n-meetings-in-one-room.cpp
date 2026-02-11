class Solution {
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;
        for (int i = 0; i < start.size(); i++){
            meetings.push_back({start[i], end[i]});
        }
        sort(meetings.begin(), meetings.end(), compare);
        int cnt = 1;
        int prevEnd = meetings[0].second;
        for (int i = 1; i < start.size(); i++){
            if (meetings[i].first > prevEnd){
                cnt++;
                prevEnd = meetings[i].second;
            }
        }
        return cnt;
    }
};