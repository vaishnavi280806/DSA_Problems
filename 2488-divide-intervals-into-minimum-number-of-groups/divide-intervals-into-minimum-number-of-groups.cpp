class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < intervals.size(); i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0;
        int n = start.size();
        int room = 0;
        int res = 0;
        
        while (i < n && j < n){
            if (start[i] <= end[j]){
                room++;
                res = max(res, room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return res;
    }
};