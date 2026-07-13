class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        #define ll long long
        int mod = 1e9 + 7;
        if (n == 0) return (a % mod) * (b % mod) % mod;

        while (n--){
            ll bit = 1LL << n;
            if ((a & bit) && (b & bit)) continue;
            else if (!(a & bit) && !(b & bit)){
                a = a | bit;
                b = b | bit;
            }
            else if (a & bit){
                if (a > b){
                    a = a ^ bit;
                    b = b | bit;
                }
            }
            else{
                if (a < b){
                    a = a | bit;
                    b = b ^ bit;
                }
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};