class Solution {
public:
    long long sumAndMultiply(int n) {
        #define ll long long
        ll sum = 0;
        ll x = 0;
        ll mul = 1;

        while (n){
            int r = (n % 10);
            sum += r;
            if (r != 0){
                x = r * mul + x;
                mul *= 10;
            }
            n /= 10;
        }
        
        //cout << x << " " << sum;
        return sum * x;
    }
};