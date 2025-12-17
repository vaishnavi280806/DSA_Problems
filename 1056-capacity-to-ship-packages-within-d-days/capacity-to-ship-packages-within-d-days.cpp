class Solution {
    int noDays(vector<int>& weights, int maxW){
        int days = 1, weight = 0;
        for (int i = 0; i < weights.size(); i++){
            if (weight + weights[i] <= maxW){
                weight += weights[i];
            }
            else{
                weight = 0;
                weight += weights[i];
                days++;
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high){
            int mid = low + (high - low)/2;
            int day = noDays(weights, mid);
            if (day <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};