class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]) inc[i] = max(inc[i], inc[j] + 1);
            }
        }
        for (int i = n-1; i >= 0; i--){
            for (int j = n-1; j > i; j--){
                if (nums[i] > nums[j]) dec[i] = max(dec[i], dec[j] + 1);
            }
        }
        
        int res = 0;
        int idx = -1;
        for (int i = 0; i < n; i++){
            //cout << inc[i] << " " << dec[i] << endl;
            if (inc[i] != 1 && dec[i] != 1) res = max(res, inc[i] + dec[i] - 1);
        }
        return res;
    }
};
