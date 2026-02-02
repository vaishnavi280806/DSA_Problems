class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return myPow(x*x, n/2);
        double ans = 1;
        long long m = abs(n);
        while (m > 0){
            if (m % 2 == 1){
                ans *= x;
                m -= 1;
            }
            else{
                x *= x;
                m /= 2;
            }
        }
        if (n < 0) return 1/ans;
        return ans;
    }
};