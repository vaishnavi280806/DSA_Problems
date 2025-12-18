class Solution {
    double helper(vector<int>& dist, int mid){
        double hr = 0, n = dist.size();
        for (int i = 0; i < n - 1; i++){
            hr += ceil((double)dist[i] / (double)mid);
        }
        return hr + (double)dist[n - 1] / (double)mid;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (ceil(hour) < dist.size()) return -1;
        int low = 1, high = 1e7;
        while (low <= high){
            int mid = low + (high - low)/2;
            double hr = helper(dist, mid);
            if (hr <= hour) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};