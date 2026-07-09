class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int end = 0;
        for (int i = 0; i < trips.size(); i++) end = max(end, trips[i][2]);
        vector<int> diff(end+1, 0);

        for (int i = 0; i < trips.size(); i++){
            diff[trips[i][1]] += trips[i][0];
            if (trips[i][2] < end + 1) diff[trips[i][2]] -= trips[i][0];
        }


        for (int i = 1; i <= end; i++){
            diff[i] += diff[i-1];
        }

        int maxi = *max_element(diff.begin(), diff.end());
        cout << maxi;
        if (maxi <= capacity) return true;
        return false;
    }
};