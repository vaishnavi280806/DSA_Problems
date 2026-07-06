class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        #define ll long long
        ll sum = 0, sqSum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; i++){
            sum += arr[i];
            sqSum += 1LL * arr[i] * arr[i];
        }
        
        ll idealSum = 1LL * n * (n+1) /2;
        ll idealSq = 1LL *n * (n+1) * (2LL *n + 1) /6;
        
        ll aminusb = sum - idealSum;
        ll a2minusb2 = sqSum - idealSq;
        ll aplusb = a2minusb2/aminusb;
        ll a = (aminusb + aplusb)/2;
        ll b = aplusb - a;
        
        
        return {(int)a, (int)b};
    }
};