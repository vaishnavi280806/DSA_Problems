class Solution {
    int time(vector<int>& piles, int k){
        int hours = 0;
        for (int i = 0; i < piles.size(); i++){
            hours += (piles[i] + k - 1 )/ k;
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high){
            int mid = low + (high - low)/2;
            int hours = time(piles, mid);
            if (hours > h) low = mid + 1;
            else high = mid;
        }
        return high;
    }
};