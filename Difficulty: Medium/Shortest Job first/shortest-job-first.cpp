// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long sum = 0;
        long long wt = 0;
        for (int i = 0; i < bt.size(); i++){
            sum += wt;
            wt += bt[i];
        }
        return sum/bt.size();
    }
};