class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high){
            int mid = low + (high - low)/2;
            if (arr[mid] <= arr[high]){ //right sorted
                high = mid;
            } 
            else{ //left sorted
                low = mid + 1;
            }
        }
        return arr[low];
    }
};