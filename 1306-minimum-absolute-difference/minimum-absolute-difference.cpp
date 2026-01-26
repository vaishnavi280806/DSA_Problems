class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        vector<vector<int>> res;
        for (int i = 1; i < arr.size(); i++){
            int d = arr[i] - arr[i-1];
            if (d < mini){
                mini = d;
                res = {{arr[i-1], arr[i]}};
            }
            else if (d == mini) res.push_back({arr[i-1], arr[i]});
        }
        return res;
    }
};