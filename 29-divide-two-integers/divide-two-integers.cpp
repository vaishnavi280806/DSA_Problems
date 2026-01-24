class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN){
            if (divisor == -1) return INT_MAX;
            if (divisor == 1) return INT_MIN;
        }
        if (dividend == INT_MAX){
            if (divisor == 1) return INT_MAX;
            if (divisor == -1) return INT_MIN + 1;
        }
        int sign = 1;
        if (dividend < 0 && divisor > 0) sign = -1;
        if (dividend > 0 && divisor < 0) sign = -1;

        long long n = llabs(dividend);
        long long d = llabs(divisor);
        int q = 0;

        while (n >= d){
            int c = 0;
            while (n >= (d << (c + 1))){
                c++;
            }
            q += (1 << c);
            n -= (d << c);
        }
        if (q == INT_MAX){
            if (sign) return INT_MAX;
            else return INT_MIN;
        }
        return q*sign;
    }
};