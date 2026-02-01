class Solution {
  public:
    vector<int> primeFac(int n) {
        vector<int> res;
        for (int i = 2; i*i <= n; i++){
            if (n % i == 0){
                res.push_back(i);
                while (n % i == 0) n = n/ i;
            }
        }
        if (n != 1) res.push_back(n);
        return res;
    }
};