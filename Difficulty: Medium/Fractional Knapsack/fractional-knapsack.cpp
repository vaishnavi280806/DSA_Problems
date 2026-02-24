class Solution {
    static bool compare(pair<int, int> p1, pair<int, int> p2){
        return 1LL * p1.first * p2.second > 1LL * p2.first * p1.second;
    }
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < val.size(); i++){
            arr.push_back({val[i], wt[i]});
        }
        sort(arr.begin(), arr.end(), compare);
        
        double ans = 0;
        int i = 0;
        while (i < arr.size() && capacity > 0){
            if (arr[i].second <= capacity){
                ans += arr[i].first;
                capacity -= arr[i].second;
            }
            else{
                ans += ((double)capacity/arr[i].second) * arr[i].first;
                capacity = 0;
            }
            i++;
        }
        return ans;
    }
};
