class Solution {
    long long helper(vector<int>& time, long long t){
        long long trip = 0;
        for (int i  = 0; i < time.size(); i++){
            trip += floor((double)t /(double)time[i]);
        }
        return trip;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = *min_element(time.begin(), time.end());
        long long high = low * totalTrips;
        while (low <= high){
            long long mid = low + (high - low)/2;
            long long trip = helper(time, mid);
            if (trip >= totalTrips){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};