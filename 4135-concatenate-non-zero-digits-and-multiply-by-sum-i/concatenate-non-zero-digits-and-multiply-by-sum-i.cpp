class Solution {
public:
    long long sumAndMultiply(int n) {
        #define ll long long
        ll sum = 0;
        ll rev = 0;
        ll x = 0;

        while (n){
            int r = (n % 10);
            if (r != 0) rev = (rev * 10) + r;
            n /= 10;
        }
        while (rev){
            int r = rev % 10;
            sum += r;
            x = x * 10 + r;
            rev /= 10;
        }
        //cout << x << " " << sum;
        return sum * x;
    }
};