class Solution {
    int helper(vector<int>& bloomDay, int days, int k){
        int count = 0, kcount = 0;
        for (int i = 0; i < bloomDay.size(); i++){
            if (bloomDay[i] <= days){
                kcount++;
            }
            else{
                kcount = 0;
            }
            if (kcount == k){
                kcount = 0;
                count++;
            }

        }
        return count;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)m * (long)k > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low <= high){
            int mid = low + (high - low)/2;
            int bouq = helper(bloomDay, mid, k);
            if (bouq >= m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};