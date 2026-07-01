class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> res;
        int maxi = INT_MIN;
        for (int i = arr.size() - 1; i >= 0; i--){
            if (arr[i] >= maxi){
                res.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};