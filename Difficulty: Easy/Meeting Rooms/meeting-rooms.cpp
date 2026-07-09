class Solution {
    static bool compare(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), compare);
        
        for (int i = 1; i < arr.size(); i++){
            if (arr[i][0] < arr[i-1][1]) return false;
        }
        return true;
    }
};