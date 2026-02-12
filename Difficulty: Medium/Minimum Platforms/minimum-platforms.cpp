class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int cnt = 0;
        int maxCnt = 0;
        int l = 0, r = 0;
        while (l < arr.size()){
            if (arr[l] <= dep[r]){
                cnt++;
                l++;
            }
            else{
                cnt--;
                r++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
