// User function Template for C++

class Solution {
  public:
    void sieve(){}
    vector<int> findPrimeFactors(int n) {
        vector<int> sieve (n+1);
        vector<int> res;
        for (int i = 1; i < n+1; i++) sieve[i] = i;
        
        for (int i = 2; i*i <= n; i++){
            if (sieve[i] == i){
                for (int j = i*i; j <= n; j += i){
                    if (sieve[j] == j) sieve[j] = i;
                }
            }
        }
        while (n != 1){
            res.push_back(sieve[n]);
            n /= sieve[n];
        }
        return res;
        
    }
};